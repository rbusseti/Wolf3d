#include "wolf3d.h"

void	ft_pickup(t_env *e)
{
    int	    i;

    i = 0;
    while (i < e->nb_sprites)
    {
	if (e->sprite[i]->pick == 1 && \
	    (int)e->sprite[i]->posx == (int)e->p->posx && \
	    (int)e->sprite[i]->posy == (int)e->p->posy && \
	    e->sprite[i]->id == e->sprite[i]->base_id)
	{
	    e->sprite[i]->id = e->sprite[i]->id + 1;
	    e->gun->ammo = e->gun->ammo + 10;
	}
	i++;
    }
}
