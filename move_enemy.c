#include "wolf3d.h"

int	ft_check_hero(int x, int y, t_env *e)
{
    if ((int)e->p->posx == x && (int)e->p->posy == y)
    {
	e->p->life--;
	return (0);
    }
    return (1);
}

int	ft_check_sprites(int x, int y, t_env *e, int j)
{
    int	    i;

    i = 0;
    while (i < e->nb_sprites)
    {
	if (i != j && e->sprite[i]->life > 0)
	{
	    if ((int)e->sprite[i]->posx == x && (int)e->sprite[i]->posy == y)
		return (0);
	}
	i++;
    }
    return (1);
}

void	ft_is_move_blocked(double dirx, double diry, t_env *e, int i)
{
    int	    x;
    int	    y;

    x = e->sprite[i]->posx + dirx * MOVESPEED / 4;
    y = e->sprite[i]->posy + diry * MOVESPEED / 4;
    if (e->map[x][(int)e->sprite[i]->posy] == '0' && \
	ft_check_sprites(x, y, e, i) && ft_check_hero(x, y, e))
	e->sprite[i]->posx += dirx * MOVESPEED / 4;
    if (e->map[(int)e->sprite[i]->posx][y] == '0' && \
	ft_check_sprites(x, y, e, i) && ft_check_hero(x, y, e))
	e->sprite[i]->posy += diry * MOVESPEED / 4;
}

void	ft_calc_dir(t_env *e, int i)
{
    double  dirx;
    double  diry;
    double  absx;
    double  absy;

    dirx = e->p->posx - e->sprite[i]->posx;
    diry = e->p->posy - e->sprite[i]->posy;
    absx = fabs(dirx);
    absy = fabs(diry);
    if (absx > absy  && absx > 1)
    {
	diry = diry / absx;
	dirx = dirx / absx;
    }
    else if (absy > 1)
    {
	    dirx = dirx / absy;
	    diry = diry / absy;
    }
    ft_is_move_blocked(dirx, diry, e, i);
}

void	ft_move_enemy(t_env *e)
{
    int	    i;

    i = 0;
    while (i < e->nb_sprites)
    {
	if (e->sprite[i]->id < e->sprite[i]->base_id + 3 && \
	    e->sprite[i]->move == 1)
	    ft_calc_dir(e, i);
	i++;
    }
}