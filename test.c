#include "mlx.h"
#include "libft.h"
#include <unistd.h>

typedef struct	s_mlx
{
    void    *mlx;
    void    *win;
}		t_mlx;


void	draw_square(t_mlx *mlx, int x, int y)
{
    int	    i;
    int	    j;

    i = 0;
    j = 0;
    while (i < 40)
    {
	while (j < 40)
	{
	    mlx_pixel_put(mlx->mlx, mlx->win, i + x, j + y, 0xFF0000);
	    j++;
	}
	i++;
	j = 0;
    }
}

int	key_hook(int keycode, t_mlx *mlx)
{
    ft_putnbr(keycode);
    ft_putchar('\n');
    if (keycode == 65307)
	exit(0);
    return (0);
}

int	mouse_hook(int button, int x, int y, t_mlx *mlx)
{
    if (button == 1)
	draw_square(mlx, x, y);
    return (0);
}

int	main(void)
{
    t_mlx   mlx;

    mlx.mlx = mlx_init();
    mlx.win = mlx_new_window(mlx.mlx, 420, 420, "Test");
    mlx_mouse_hook(mlx.win, mouse_hook, &mlx);
    mlx_key_hook(mlx.win, key_hook, &mlx);
    mlx_loop(mlx.mlx);
    return (0);
}
