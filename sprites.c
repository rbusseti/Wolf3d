# include <wolf3d.h>

void	ft_calc_height(t_calcsp *csp)
{
    csp->height = abs(SCRH / csp->transy);
    csp->top = SCRH / 2 - csp->height / 2;
    if (csp->top < 0)
	csp->top = 0;
    csp->bot = SCRH / 2 + csp->height / 2;
    if (csp->bot >= SCRH)
	csp->bot = SCRH - 1;
}

void	ft_calc_width(t_calcsp *csp)
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

void	ft_draw_sprite(t_env *e, t_calcsp csp, int c_sprite)
{
    int	    i;
    int	    j;
    int	    d;
    int	    x;
    int	    y;
    unsigned long   icolor;

    i = csp.left;
    while (i < csp.right)
    {
	if (csp.transy > 0 && i >= 0 && i < SCRW && csp.transy < e->sdist[i])
	{
	    x = (i - (csp.rsave - csp.width)) * C_SIZE / csp.width;
	    j = csp.top;
	    while (j < csp.bot)
	    {
		d = j - SCRH / 2 + csp.height / 2;
		y = d * C_SIZE / csp.height;
		icolor = ft_get_color(y, x, e->tex[(e->sprite)[c_sprite]->id], e->sprite[c_sprite]->dist / 10);
		if (icolor != 0)
		    ft_pixel_put_to_image(icolor, e->idata, i, j);
		j++;
	    }
	}
	i++;
    }
}

void	ft_init_csp(t_calcsp *csp, t_env *e, int i)
{
    csp->posx = (e->sprite[i])->posx - e->p->posx;
    csp->posy = (e->sprite[i])->posy - e->p->posy;
    csp->inv = 1.0 / (e->p->planex * e->p->diry - e->p->planey * e->p->dirx);
    csp->transx = csp->inv * (e->p->diry * csp->posx - e->p->dirx * csp->posy);
    csp->transy = csp->inv * (e->p->planex * csp->posy - e->p->planey * csp->posx);
    csp->screenx = (SCRW / 2) * (1 + csp->transx / csp->transy);
}

void	ft_calc_sprites(t_env *e)
{
    int		i;
    t_calcsp	csp;

    i = 0;
    while (i < e->nb_sprites)
    {
	e->sprite[i]->dist = ((e->p->posx - e->sprite[i]->posx)\
			      * (e->p->posx - e->sprite[i]->posx)\
			      + (e->p->posy - e->sprite[i]->posy)\
			      * (e->p->posy - e->sprite[i]->posy));
	i++;
    }
    ft_comb_sort(e->sprite, e->nb_sprites - 1);
    i = 0;
    while (i < e->nb_sprites)
    {
	ft_init_csp(&csp, e, i);
	ft_calc_height(&csp);
	ft_calc_width(&csp);
	ft_draw_sprite(e, csp, i);
	i++;
    }
}
