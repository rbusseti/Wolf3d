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

void	ft_move_character(t_env *e)
{
    int	    x;
    int	    y;

    
    if (e->key->left == 1)
	ft_turn_left(e->p);
    else if (e->key->right == 1)
	ft_turn_right(e->p);
    if (e->key->up == 1)
    {
	x = e->p->posx + e->p->dirx * MOVESPEED;
	y = e->p->posy + e->p->diry * MOVESPEED;
	if (e->map[x][(int)e->p->posy] == '0' || e->map[x][(int)e->p->posy] == '3')
	    e->p->posx += e->p->dirx * MOVESPEED;
	if (e->map[(int)e->p->posx][y] == '0' || e->map[(int)e->p->posx][y] == '3')
	    e->p->posy += e->p->diry * MOVESPEED;
    }
    else if (e->key->down == 1)
    {
	x = e->p->posx - e->p->dirx * MOVESPEED;
	y = e->p->posy - e->p->diry * MOVESPEED;
	if (e->map[x][(int)e->p->posy] == '0' || e->map[x][(int)e->p->posy] == '3')
	    e->p->posx -= e->p->dirx * MOVESPEED;
	if (e->map[(int)e->p->posx][y] == '0' || e->map[(int)e->p->posx][y] == '3')
	    e->p->posy -= e->p->diry * MOVESPEED;
    }
}
