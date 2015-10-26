#include "wolf3d.h"

void	ft_pixel_put_to_image(unsigned long color, t_idata *idata, int y, int x)
{
    unsigned char   r;
    unsigned char   g;
    unsigned char   b;

    r = ((color & 0xFF0000) >> 16);
    g = ((color & 0xFF00) >> 8);
    b = ((color & 0xFF));

    idata->adr[x * idata->line + y * idata->bpp / 8] = b;
    idata->adr[x * idata->line + y * idata->bpp / 8 + 1] = g;
    idata->adr[x * idata->line + y * idata->bpp / 8 + 2] = r;
}

void	ft_init_floor(t_floor *floor, t_ray *ray)
{
    if (ray->side == 0 && ray->dirx > 0)
    {
	floor->wallx = ray->mapx;
	floor->wally = ray->mapy + ray->wallx;
    }
    else if (ray->side == 0 && ray->dirx < 0)
    {
	floor->wallx = ray->mapx + 1.0;
	floor->wally = ray->mapy + ray->wallx;
    }
    else if (ray->side == 1 && ray->diry > 0)
    {
	floor->wallx = ray->mapx + ray->wallx;
	floor->wally = ray->mapy;
    }
    else
    {
	floor->wallx = ray->mapx + ray->wallx;
	floor->wally = ray->mapy + 1.0;
    }
}

void    ft_draw(int i, t_env *e, t_ray *ray)
{
    int		    j;
    int		    texnum;
    unsigned long   icolor;
    t_floor	    floor;

    texnum = e->map[ray->mapx][ray->mapy] - '0';
    j = ray->walltop;
    while (j <= ray->wallbot)
    {
	icolor = ft_get_wall_texture(e->tex[texnum], ray, j);
	ft_pixel_put_to_image(icolor, e->idata, i, j);
        j++;
    }
    ft_init_floor(&floor, ray);
    while (j < SCRH)
    {
	icolor = ft_get_floor_texture(e->tex, ray, &floor, j, e->map);
	ft_pixel_put_to_image(icolor, e->idata, i, j);
	icolor = ft_get_floor_texture(e->tex, ray, &floor, j, NULL);
	ft_pixel_put_to_image(icolor, e->idata, i, SCRH - j);
        j++;
    }
}
