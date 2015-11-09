#include "wolf3d.h"

void    ft_turn_left(t_play *p)
{
    double  olddirx;
    double  oldplanex;

    olddirx = p->dirx;
    oldplanex = p->planex;
    p->dirx = p->dirx * cos(ROTSPEED) - p->diry * sin(ROTSPEED);
    p->diry = olddirx * sin(ROTSPEED) + p->diry * cos(ROTSPEED);
    p->planex = p->planex * cos(ROTSPEED) - p->planey * sin(ROTSPEED);
    p->planey = oldplanex * sin(ROTSPEED) + p->planey * cos(ROTSPEED);
}

void    ft_turn_right(t_play *p)
{
    double  olddirx;
    double  oldplanex;

    olddirx = p->dirx;
    oldplanex = p->planex;
    p->dirx = p->dirx * cos(-ROTSPEED) - p->diry * sin(-ROTSPEED);
    p->diry = olddirx * sin(-ROTSPEED) + p->diry * cos(-ROTSPEED);
    p->planex = p->planex * cos(-ROTSPEED) - p->planey * sin(-ROTSPEED);
    p->planey = oldplanex * sin(-ROTSPEED) + p->planey * cos(-ROTSPEED);
}

int	ft_check_sprites_col(int x, int y, t_env *e)
{
    int	    i;

    i = 0;
    while (i < e->nb_sprites)
    {
	if ((int)e->sprite[i]->posx == (int)x && \
	    (int)e->sprite[i]->posy == (int)y && \
	    e->sprite[i]->life != 0 && e->sprite[i]->pick != 1)
	    return (0);
	i++;
    }
    return (1);
}

void	ft_check_collisions(t_env *e, double x, double y, int type)
{
    if (type == 1)
    {
	if ((e->map[(int)x][(int)e->p->posy] == '0' ||	\
	     e->map[(int)x][(int)e->p->posy] == '3') && \
	    ft_check_sprites_col(x, e->p->posy, e))
	    e->p->posx += e->p->dirx * MOVESPEED;
	if ((e->map[(int)e->p->posx][(int)y] == '0' ||	\
	     e->map[(int)e->p->posx][(int)y] == '3') &&	\
	    ft_check_sprites_col(e->p->posx, y, e))
	    e->p->posy += e->p->diry * MOVESPEED;
    }
    else if (type == 2)
    {
	if ((e->map[(int)e->p->posx][(int)y] == '0' ||	\
	     e->map[(int)e->p->posx][(int)y] == '3') && \
	    ft_check_sprites_col(e->p->posx, y, e))
	    e->p->posy -= e->p->diry * MOVESPEED;
	if ((e->map[(int)x][(int)e->p->posy] == '0' ||	\
	     e->map[(int)x][(int)e->p->posy] == '3') && \
	    ft_check_sprites_col(x, e->p->posy, e))
	    e->p->posx -= e->p->dirx * MOVESPEED;
    }
}

void	ft_move_character(t_env *e)
{
    double   x;
    double   y;

    
    if (e->key->left == 1)
	ft_turn_left(e->p);
    else if (e->key->right == 1)
	ft_turn_right(e->p);
    if (e->key->up == 1)
    {
	x = e->p->posx + e->p->dirx * MOVESPEED;
	y = e->p->posy + e->p->diry * MOVESPEED;
	ft_check_collisions(e, x, y, 1);
    }
    else if (e->key->down == 1)
    {
	x = e->p->posx - e->p->dirx * MOVESPEED;
	y = e->p->posy - e->p->diry * MOVESPEED;
	ft_check_collisions(e, x, y, 2);
    }
}
