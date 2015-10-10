#include "wolf3d.h"

#include <X11/Xlib.h>

void	ft_hook(t_env *e)
{
    mlx_expose_hook(e->win, &ft_expose_hook, e);
    mlx_mouse_hook(e->win, &ft_mouse_hook, e);
    mlx_hook(e->win, KeyRelease, KeyReleaseMask, &ft_key_released, e);
    mlx_hook(e->win, KeyPress, KeyPressMask, &ft_key_pressed, e);
    mlx_loop_hook(e->mlx, &ft_loop_hook, e);
    mlx_loop(e->mlx);
}

int	main(int argc, char **argv)
{
    t_env   e;
    char    *map_name;

    if (argc != 2)
        map_name = "Ressources/map0.txt";
    else
        map_name = ft_strjoin("Ressources/", argv[1]);
    ft_putendl(map_name);
    e.mlx = mlx_init();
    e.win = mlx_new_window(e.mlx, SCRW, SCRH, "Wolf3d");
    e.img = mlx_new_image(e.mlx, SCRW, SCRH);
    mlx_do_key_autorepeatoff(e.mlx);
    ft_init_world(&e, map_name);
    ft_hook(&e);
    return (0);
}
