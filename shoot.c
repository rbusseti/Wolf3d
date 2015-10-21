#include "wolf3d.h"

void	ft_shoot(t_env *e)
{
    int	    c;
    int	    c2;

    if (e->gun->count != 0 && e->gun->count < 9)
	e->gun->count++;
    else if (e->gun->count == 9)
	e->gun->count = 0;
    if (e->key->space == 1 && e->gun->count == 0 && e->gun->ammo > 0)
    {
	e->gun->count++;
	e->key->space = 0;
	e->gun->ammo--;
    }
    c = e->gun->count / 2;
    c2 = e->gun->count / 2 + 1;
    if (c2 > 5)
	c2 = 5;
    if (c > 4)
	c = 4;
    e->gun->gap = e->gun->split[c2] - e->gun->split[c];
}
