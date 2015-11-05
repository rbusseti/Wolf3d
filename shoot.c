#include "wolf3d.h"

void    ft_calc_w(t_calcsp *csp)
{
    csp->width = abs(SCRH / csp->transy);
    csp->left = csp->screenx - csp->width / 2;
    csp->lsave = csp->left;
    if (csp->left < 0)
        csp->left = 0;
    csp->right = csp->screenx + csp->width / 2;
    csp->rsave = csp->right;
    if (csp->right >= SCRW)
        csp->right = SCRW - 1;
}

void    ft_in_csp(t_calcsp *csp, t_env *e, int i)
{
    csp->posx = (e->sprite[i])->posx - e->p->posx;
    csp->posy = (e->sprite[i])->posy - e->p->posy;
    csp->inv = 1.0 / (e->p->planex * e->p->diry - e->p->planey * e->p->dirx);
    csp->transx = csp->inv * (e->p->diry * csp->posx - e->p->dirx * csp->posy);
    csp->transy = csp->inv * (e->p->planex * csp->posy - e->p->planey * csp->posx);
    csp->screenx = (SCRW / 2) * (1 + csp->transx / csp->transy);
}

int    ft_calc_impact(t_env *e, t_calcsp csp, int c_sprite)
{
    int	    i;

    i = SCRW / 2;
    if (csp.transy > 0 && i >= 0 && i < SCRW && csp.transy < e->sdist[i])
    {
	if (i > csp.left && i < csp.right && e->sprite[c_sprite]->life > 0)
	{
	    e->sprite[c_sprite]->life--;
	    if (e->sprite[c_sprite]->id < e->sprite[c_sprite]->base_id \
		+ e->sprite[c_sprite]->frame)
		e->sprite[c_sprite]->id++;
	    return (1);
	}
    }
    return (0);
}

void	ft_lauch_bullet(t_env *e)
{
    int         i;
    t_calcsp    csp;
    
    i = 0;
    while (i < e->nb_sprites)
    {
	e->sprite[i]->dist = ((e->p->posx - e->sprite[i]->posx)		\
                              * (e->p->posx - e->sprite[i]->posx)\
                              + (e->p->posy - e->sprite[i]->posy)\
                              * (e->p->posy - e->sprite[i]->posy));
	i++;
    }
    ft_comb_sort(e->sprite, e->nb_sprites - 1);
    i = e->nb_sprites - 1;
    while (i >= 0)
    {
	ft_in_csp(&csp, e, i);
	ft_calc_w(&csp);
	if (ft_calc_impact(e, csp, i))
	    return;
	i--;
    }
}

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
	ft_lauch_bullet(e);
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
