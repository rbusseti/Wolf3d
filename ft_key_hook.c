#include "wolf3d.h"

int	ft_key_hook(int keycode, t_env *e)
{
    if (keycode == ESC)
	exit(0);
    if (keycode == RIGHT)
	e->cam->angle = ft_add_angle(e->cam->angle, -5);
    else if (keycode == LEFT)
	e->cam->angle = ft_add_angle(e->cam->angle, 5);
    update(e);
    return (0);
}
