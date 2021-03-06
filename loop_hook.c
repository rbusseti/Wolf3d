#include "wolf3d.h"
#include <stdio.h>

int	ft_loop_hook(t_env *e)
{
    ft_move_character(e);
    ft_move_enemy(e);
    if (e->p->life < 1)
    {
	ft_restart_level(e);
	return (0);
    }
    ft_shoot(e);
    ft_teleport(e);
    ft_pickup(e);
    e->frame++;
    if (e->t1 == 0)
	time(&(e->t1));
    else
    {
	time(&(e->t2));
	if (e->t2 - e->t1 >= 1)
	{
	    printf("%d\n", e->frame);
	    e->frame = 0;
	    e->t1 = e->t2;
	}
    }
    ft_update(e);
    return (0);
}
