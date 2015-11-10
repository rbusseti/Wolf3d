#include "wolf3d.h"

t_box	ft_init_box(double x, double y)
{
    t_box   box;

    box.north = y - 0.5;
    box.south = y + 0.5;
    box.east = x + 0.5;
    box.west = x - 0.5;
    return (box);
}

int	ft_check_box(double x1, double y1, double x2, double y2)
{
    t_box   box1;
    t_box   box2;

    box1 = ft_init_box(x1, y1);
    box2 = ft_init_box(x2, y2);
    if (box1.north >= box2.south)
	return (0);
    else if (box1.south <= box2.north)
	return (0);
    else if (box1.east <= box2.west)
	return (0);
    else if (box1.west >= box2.east)
	return (0);
    else
	return (1);
}
