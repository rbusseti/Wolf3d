#include "wolf3d.h"

double	ft_deg_to_rad(double angle)
{
    double  rad;
/*
    if (angle < 5)
	angle = 5;
    else if (angle > 85 && angle < 95)
	angle = 85;
    else if (angle > 175 && angle < 185)
	angle = 175;
    else if (angle > 265 && angle < 275)
	angle = 265;
    else if (angle > 355)
	angle = 355;
*/
    rad = angle * M_PI / 180;
    return (rad);
}

t_table	*ft_trigo_table(void)
{
    int	    i;
    t_table *tab;
    double  rad;

    i = 0;
    tab = malloc(sizeof(*tab));
    tab->cos = malloc(sizeof(double) * 360);
    tab->sin = malloc(sizeof(double) * 360);
    tab->tan = malloc(sizeof(double) * 360);
    while (i < 360)
    {
	rad = ft_deg_to_rad(i) + 0.001;
	tab->cos[i] = cos(rad);
	tab->sin[i] = sin(rad);
	tab->tan[i] = tan(rad);
	i++;
    }
    return (tab);
}
