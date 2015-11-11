#include "wolf3d.h"

void    ft_draw_gun(t_env *e)
{
    int             j;
    int		    i;
    int		    frame;
    unsigned long   icolor;

    frame = e->gun->count / 2;
    j = SCRH - 150;
    i = GUNX - e->gun->gap + 1;
    while (i < GUNX)
    {
	while (j < SCRH)
	{
	    
	    icolor = ft_get_color(j - SCRH + 150, i - (GUNX - e->gun->gap)\
                     + e->gun->split[frame], e->tex[e->gun->texnum], 0);
	    if (icolor != 0)
		ft_pixel_put_to_image(icolor, e->idata, i, j);
	    j++;
	}
	i++;
	j = SCRH - 150;
    }
}

