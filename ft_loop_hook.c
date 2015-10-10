#include "wolf3d.h"

int	ft_loop_hook(t_env *e)
{
    update(e);
    return (0);
}
