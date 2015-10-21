#include "wolf3d.h"

void	ft_jump_to(t_list **slist, t_env *e)
{
    t_tp    *tp;
    t_list  *list;

    list = *slist;
    while (list != NULL)
    {
	tp = list->content;
	if (tp->posx == (int)e->p->posx && tp->posy == (int)e->p->posy)
	{
	    e->p->posx = tp->destx + 0.5;
	    e->p->posy = tp->desty + 0.5;
	    e->p->is_tp = 1;
	    return;
	}
	list = list->next;
    }
}

void	ft_teleport(t_env *e)
{
    if (e->p->is_tp == 1)
    {
	if (e->map[(int)e->p->posx][(int)e->p->posy] != '3')
	    e->p->is_tp = 0;
	return;
    }
    if (e->map[(int)e->p->posx][(int)e->p->posy] == '3')
	ft_jump_to(&(e->tp), e);
}
