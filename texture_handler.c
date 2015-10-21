#include "wolf3d.h"

unsigned long	ft_get_color(int x, int y, t_idata *img, double truedist)
{
    unsigned char   r;
    unsigned char   g;
    unsigned char   b;
    unsigned long   color;

    b = img->adr[(int)(x) * img->line + (int)(y) * img->bpp / 8];
    g = img->adr[(int)(x) * img->line + (int)(y) * img->bpp /  8 + 1];
    r = img->adr[(int)(x) * img->line + (int)(y) * img->bpp / 8 + 2];
    while (truedist > FOG)
    {
	b = b * 0.9;
	g = g * 0.9;
	r = r * 0.9;
	truedist = truedist - 0.3;
    }
    color = ((r << 16) & 0xff0000) | ((g << 8) & 0xff00) | ((b & 0xff));
    return (color);
}

unsigned long	ft_get_floor_texture(t_idata **img, t_ray *ray, t_floor *floor, int j, char **map)
{
    double  dist;
    double  weight;
    int	    texnum;

    dist = SCRH / (2 * j - SCRH);
    weight = (dist / ray->truedist);
    floor->currentx = weight * floor->wallx + (1.0 - weight) * ray->posx;
    floor->currenty = weight * floor->wally + (1.0 - weight) * ray->posy;
    floor->texx = (int)(floor->currentx * C_SIZE) % (int)C_SIZE;
    floor->texy = (int)(floor->currenty * C_SIZE) % (int)C_SIZE;
    if (map == NULL)
	texnum = 2;
    else
	texnum = map[(int)floor->currentx][(int)floor->currenty] - '0';
    return (ft_get_color(floor->texy, floor->texx, img[texnum], dist));
}

unsigned long   ft_get_wall_texture(t_idata *wall, t_ray *ray, int j)
{
    double          x;
    double          y;

    if (ray->side == 1)
        x = ray->posx + ((ray->mapy - ray->posy + (1.0 - ray->stepy) / 2)\
			 / ray->diry) * ray->dirx;
    else
        x = ray->posy + ((ray->mapx - ray->posx + (1.0 - ray->stepx) / 2)\
			 / ray->dirx) * ray->diry;
    x = x - (int)(x);
    ray->wallx = x;
    x = (int)(x * C_SIZE);
    if ((ray->side == 0 && ray->dirx > 0) || (ray->side == 1 && ray->diry < 0))
        x = C_SIZE - x - 1;
    y = (j * 2 - SCRH + ray->wallh) * (C_SIZE / 2) / ray->wallh;
    return (ft_get_color(y, x, wall, ray->truedist));
}
