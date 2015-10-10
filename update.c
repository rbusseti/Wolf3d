#include "wolf3d.h"

void	ft_init_ray(t_ray *ray, t_env *e)
{
    ray->posx = e->p->posx;
    ray->posy = e->p->posy;
    ray->dirx = e->p->dirx + e->p->planex * e->camx;
    ray->diry = e->p->diry + e->p->planey * e->camx;
    ray->nextx = sqrt(1 + (ray->diry * ray->diry) / (ray->dirx * ray->dirx));
    ray->nexty = sqrt(1 + (ray->dirx * ray->dirx) / (ray->diry * ray->diry));
    e->p->mapx = (int)ray->posx;
    e->p->mapy = (int)ray->posy;
}

int	ft_next_intersect(t_ray *ray, t_env *e)
{
    if (ray->firstx < ray->firsty)
    {
	ray->firstx = ray->firstx + ray->nextx;
	e->p->mapx = e->p->mapx + ray->stepx;
	ray->side = 0;
    }
    else
    {
	ray->firsty = ray->firsty + ray->nexty;
	e->p->mapy = e->p->mapy + ray->stepy;
	ray->side = 1;
    }
    if (e->map[e->p->mapx][e->p->mapy] != '0')
	return (1);
    return (0);
}

void	ft_find_intersect(t_ray *ray, t_env *e)
{
    if (ray->dirx < 0)
    {
	ray->stepx = -1;
	ray->firstx = (ray->posx - e->p->mapx) * ray->nextx;
    }
    else
    {
	ray->stepx = 1;
	ray->firstx = (e->p->mapx + 1.0 - ray->posx) * ray->nextx;
    }
    if (ray->diry < 0)
    {
	ray->stepy = -1;
	ray->firsty = (ray->posy - e->p->mapy) * ray->nexty;
    }
    else
    {
	ray->stepy = 1;
	ray->firsty = (e->p->mapy + 1.0 - ray->posy) * ray->nexty;
    }
    while (ft_next_intersect(ray, e) == 0)
	;
}

void	ft_calc_wall(t_ray *ray, t_env *e, int i)
{
    int	    wallh;
    t_draw  pen;

    wallh = abs((int)(SCRH / ray->truedist));
    pen.walltop = -wallh / 2 + SCRH / 2;
    if (pen.walltop < 0)
	pen.walltop = 0;
    pen.wallbot = wallh / 2 + SCRH / 2;
    if (pen.wallbot >= SCRH)
	pen.wallbot = SCRH - 1;
    pen.side = ray->side;
    pen.dirx = ray->dirx;
    pen.diry = ray->diry;
    ft_draw(pen, i, e);
}

void	ft_update(t_env *e)
{
    int	    i;
    t_ray   ray;

    i = 0;
    while (i < SCRW)
    {
	e->camx = 2 * i / (double)SCRW -1;
	ft_init_ray(&ray, e);
	ft_find_intersect(&ray, e);
	if (ray.side == 0)
	    ray.truedist = fabs(((double)e->p->mapx - ray.posx + (1 - ray.stepx) / 2) / ray.dirx);
	else
	    ray.truedist = fabs(((double)e->p->mapy - ray.posy + (1 - ray.stepy) / 2) / ray.diry);
	ft_calc_wall(&ray, e, i);
	i++;
    }
    mlx_clear_window(e->mlx, e->win);
    mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}
