#include "wolf3d.h"

int	ft_key_released(int keycode, t_env *e)
{
    if (keycode == ESC)
    {
	mlx_destroy_window(e->mlx, e->win);
	mlx_do_key_autorepeaton(e->mlx);
	exit(0);
    }
    if (keycode == LEFT)
	e->key->left = 0;
    if (keycode == RIGHT)
	e->key->right = 0;
    if (keycode == UP)
	e->key->up = 0;
    if (keycode == DOWN)
	e->key->down = 0;
    if (keycode == SPACE)
	e->key->space = 0;
    return (0);
}

int	ft_key_pressed(int keycode, t_env *e)
{
    if (keycode == LEFT)
	e->key->left = 1;
    if (keycode == RIGHT)
	e->key->right = 1;
    if (keycode == UP)
	e->key->up = 1;
    if (keycode == DOWN)
	e->key->down = 1;
    if (keycode == SPACE)
	e->key->space = 1;
    return (0);
}
