#include "wolf3d.h"

void	ft_draw_numbers(int x, int y, t_env *e, int n)
{
    unsigned int    icolor;
    int	    i;
    int	    j;

    i = 0;
    j = 0;
    while (i < 40)
    {
	while (j < 40)
	{
	    icolor = ft_get_color(i, j + n * 40, e->tex[13], 0);
	    if (icolor != 0)
		ft_pixel_put_to_image(icolor, e->idata, j + x, i + y);
	    j++;
	}
	j = 0;
	i++;
    }
}

void	ft_put_numbers(int x, int y, t_env *e , int n)
{
    int	    n2;

    if (n > 99)
	n = 99;
    n2 = n % 10;
    n = n / 10;
    if (n > 0)
	ft_draw_numbers(x, y, e, n);
    ft_draw_numbers(x + 35, y, e, n2);
}

void	ft_draw_overlay(t_env *e)
{
    int	    i;
    int	    j;
    unsigned int icolor;
   
    i = SCRH;
    j = 0;
    while (i < SCRH + 80)
    {
	while (j < SCRW)
	{
	    icolor = ft_get_color(i - SCRH, j, e->tex[12], 0);
	    ft_pixel_put_to_image(icolor, e->idata, j, i);
	    j++;
	}
	i++;
	j = 0;
    }
    ft_put_numbers(AMMO_X, AMMO_Y, e, e->gun->ammo);
    ft_put_numbers(LIFE_X, LIFE_Y, e, e->p->life);
}
