#include "wolf3d.h"

void	ft_restart_sprites(t_sprite **sprite, int nb_sprites)
{
    int	    i;

    i = 0;
    while (i < nb_sprites)
    {
	sprite[i]->posx = sprite[i]->savex;
	sprite[i]->posy = sprite[i]->savey;
	sprite[i]->life += (sprite[i]->id - sprite[i]->base_id);
	sprite[i]->id = sprite[i]->base_id;
	i++;
    }
}

void	ft_restart_level(t_env *e)
{
    e->p->posx = e->p->basex;
    e->p->posy = e->p->basey;
    e->p->dirx = -1;
    e->p->diry = 0;
    e->p->planex = 0;
    e->p->planey = 0.66;
    e->p->life = 99;
    e->gun->ammo = 10;
    ft_restart_sprites(e->sprite, e->nb_sprites);
}
