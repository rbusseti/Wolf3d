#include "update.h"
# include <stdio.h>

void    print_struct(t_ray ray)
{
    printf("firstx: %f \n", ray.firstx);
    printf("firsty: %f \n", ray.firsty);
    printf("gapx: %f \n", ray.gapx);
    printf("gapy: %f \n", ray.gapy);
    printf("dist: %f \n\n", ray.dist);
}

t_ray	calc_next_ray(t_ray ray, char **map)
{
    while (1)
    {
/*
	ft_putnbr((int)(ray.firstx / C_SIZE));//
	ft_putchar('\n');//
	ft_putnbr((int)(ray.firsty / C_SIZE));//
	ft_putchar('\n');//
*/
	ray.firstx = ray.firstx + ray.gapx;
	ray.firsty = ray.firsty + ray.gapy;
	if (map[(int)(ray.firsty / C_SIZE)][(int)(ray.firstx / C_SIZE)] != '0')
	    return (ray);
    }
    return (ray);
}

t_ray	calc_hray_intersect(t_env *e, double rayangle)
{
    t_ray   hray;

    if (rayangle < M_PI)
    {
	hray.firsty = (int)(e->cam->posy / C_SIZE) * C_SIZE - 1;
	hray.gapy = -C_SIZE;
//	printf("camposy: %f \n firsty: %f \n gapy: %f \n",e->cam->posy, hray.firsty, hray.gapy);
    }
    else
    {
	hray.firsty = (int)(e->cam->posy / C_SIZE) * C_SIZE + C_SIZE;
	hray.gapy = C_SIZE;
//	printf("camposy: %f \n firsty: %f \n gapy: %f \n",e->cam->posy, hray.firsty, hray.gapy);
    }
    hray.firstx = e->cam->posx + (e->cam->posy - hray.firsty) / tan(rayangle);
//    printf("camposx: %f \n camposy: %f \n firsty: %f \n tangente: %f \n firstx: %f \n\n", e->cam->posx, e->cam->posy, hray.firsty, tan(rayangle), hray.firstx);
    hray.gapx = C_SIZE / tan(rayangle);
/*
    ft_putendl("avant le if?");//
    ft_putnbr((int)(hray.firstx));//
    ft_putchar('\n');//
    ft_putnbr((int)(hray.firsty));//
    ft_putchar('\n');//
*/
    if ((e->map)[(int)(hray.firsty / C_SIZE)][(int)(hray.firstx / C_SIZE)] != '0')
    {
	hray.interx = hray.firstx;
	hray.intery = hray.firsty;
	return (hray);
    }
    return (calc_next_ray(hray, e->map));
}

t_ray	calc_vray_intersect(t_env *e, double rayangle)
{
    t_ray   vray;

    if (rayangle >= M_PI / 2 && rayangle < 3 * M_PI / 2)
    {
	vray.firstx = (e->cam->posx / C_SIZE) * C_SIZE - 1;
	vray.gapx = -C_SIZE;
    }
    else
    {
	vray.firstx = (e->cam->posx / C_SIZE) * C_SIZE + C_SIZE;
	vray.gapx = C_SIZE;
    }
    vray.firsty = e->cam->posy + (e->cam->posx - vray.firstx) * tan(rayangle);
    vray.gapy = C_SIZE * tan(rayangle);
    if ((e->map)[(int)(vray.firsty / C_SIZE)][(int)(vray.firstx / C_SIZE)] != '0')
    {
	vray.interx = vray.firstx;
	vray.intery = vray.firsty;
	return (vray);
    }
    return (calc_next_ray(vray, e->map));
}

void	calc_dist(double hdist, double vdist, t_env *e, int i, double rayangle, double angle)
{
    double  dist;
    int	    wallh;
    int	    walltop;

    if (hdist < vdist)
	dist = hdist;
    else
	dist = vdist;
    if (i >= 160)
	dist = dist * cos(rayangle - angle);
    else
	dist = dist * cos(rayangle - angle);
    wallh = 64 / dist * e->cam->dist;
    walltop = (SCRH / 2) - (wallh / 2);
    draw(wallh, walltop, i, e);
}

void	aff_map(char **map)
{
    int	    i;

    i = 0;
    while (map[i] != NULL)
    {
	ft_putendl(map[i]);
	i++;
    }
}

void	update(t_env *e)
{
    t_ray   hray;
    t_ray   vray;
    int	    i;
    double  rayangle;

    i = 0;
    rayangle = ft_add_angle(e->cam->angle, -(FOV / 2));
 
    while (i < SCRW)
    {
//	aff_map(e->map);//
//	ft_putendl("boucle");//
	if (i < 160)
	{
	    printf("i: %d \n", i);
	    printf("rayangle: %f \n", rayangle);//
//	    printf("nextray: %f \n", e->cam->next_ray);//
	}
	if (rayangle > 6.19)
	{
	    hray = calc_hray_intersect(e, 6.19);
//	ft_putendl("avant vray");//
	    vray = calc_vray_intersect(e, 6.19);
	}
	else if (rayangle < 0.09)
	{
	    hray = calc_hray_intersect(e, 0.09);
//	ft_putendl("avant vray");//
	    vray = calc_vray_intersect(e, 0.09);
	}
	else
	{
	    hray = calc_hray_intersect(e, rayangle);
//	ft_putendl("avant vray");//
	    vray = calc_vray_intersect(e, rayangle);
	}
//	hray.dist = abs(e->cam->posx - hray.firstx) / cos(rayangle);
//	vray.dist = abs(e->cam->posx - vray.firstx) / cos(rayangle);
	hray.dist = sqrt((e->cam->posx - hray.firstx) * (e->cam->posx - hray.firstx) + (e->cam->posy - hray.firsty) * (e->cam->posy - hray.firsty));
	vray.dist = sqrt((e->cam->posx - vray.firstx) * (e->cam->posx - vray.firstx) + (e->cam->posy - vray.firsty) * (e->cam->posy - vray.firsty));
//	print_struct(hray);//
//	print_struct(vray);//
	if (rayangle > 6.19)
	    calc_dist(hray.dist, vray.dist, e, i, 6.19, e->cam->angle);
	else if (rayangle < 0.09)
	    calc_dist(hray.dist, vray.dist, e, i, 0.09, e->cam->angle);
	else
	    calc_dist(hray.dist, vray.dist, e, i, rayangle, e->cam->angle);
	rayangle = ft_add_angle(rayangle, e->cam->next_ray);
	i++;
    }
}
