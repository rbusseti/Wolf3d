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

void	ft_pixel_put_to_image(unsigned long color, t_idata *idata, int x, int y)
{
    unsigned char   r;
    unsigned char   g;
    unsigned char   b;

    r = ((color & 0xFF0000) >> 16);
    g = ((color & 0xFF00) >> 8);
    b = ((color & 0xFF));

    idata->adr[y * idata->line + x * idata->bpp / 8] = b;
    idata->adr[y * idata->line + x * idata->bpp / 8 + 1] = g;
    idata->adr[y * idata->line + x * idata->bpp / 8 + 2] = r;
}

void    ft_draw(t_draw pen, int i, t_env *e)
{
    int		    j;
    unsigned long   icolor;

    j = 0;

    icolor = mlx_get_color_value(e->mlx, 0xFFFFFF);
    while (j < pen.walltop)
    {
	ft_pixel_put_to_image(icolor, e->idata, i, j);
        j++;
    }
    icolor = mlx_get_color_value(e->mlx, ft_choose_color(pen));
    while (j <= pen.wallbot)
    {
	ft_pixel_put_to_image(icolor, e->idata, i, j);
        j++;
    }
    icolor = mlx_get_color_value(e->mlx, 0x000000);
    while (j < SCRH)
    {
	ft_pixel_put_to_image(icolor, e->idata, i, j);
        j++;
    }
}
