#include "wolf3d.h"

int	ft_loop_hook(t_env *e)
{
    ft_move_character(e);
    ft_update(e);
    return (0);
}
