#include "wolf3d.h"

int	ft_choose_color(t_draw pen)
{
    if (pen.side == 0)
    {
	if (pen.dirx > 0)
	    return (0x99FF99);
	else
	    return(0x996666);
    }
    else
    {
	if (pen.diry > 0)
	    return (0x999966);
	else
	    return(0x993366);
    }
}

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

void	ft_draw_sword(int i, t_env *e)
{
    int		    j;
    unsigned long   icolor;

    j = SCRH - 100;
    while (j < SCRH)
    {
	icolor = ft_get_color(j - SCRH + 100, i - SCRW + 350, e->tex->sword);
	if (icolor != 0)
	    ft_pixel_put_to_image(icolor, e->idata, i, j);
	j++;
    }
}

void    ft_draw(t_draw pen, int i, t_env *e, t_ray *ray)
{
    int		    j;
    unsigned long   icolor;
    t_floor	    floor;

    j = pen.walltop;
    while (j <= pen.wallbot)
    {
	icolor = ft_get_wall_texture(e->tex->wall, ray, &pen, j);
	ft_pixel_put_to_image(icolor, e->idata, i, j);
        j++;
    }
    ft_init_floor(&floor, ray);
    while (j < SCRH)
    {
	icolor = 0;
	icolor = ft_get_floor_texture(e->tex->floor, ray, &floor, j);
	ft_pixel_put_to_image(icolor, e->idata, i, j);
	icolor = ft_get_floor_texture(e->tex->sky, ray, &floor, j);
	ft_pixel_put_to_image(icolor, e->idata, i, SCRH - j - 1);
        j++;
    }
    if (i >= SCRW - 350 && i < SCRW - 250)
    {
	ft_draw_sword(i, e);
    }
}
