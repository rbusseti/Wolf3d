#include "wolf3d.h"

void    ft_print_list(t_list **list)
{
    t_list  *slist;
    t_tp    *tp;

    slist = *list;
    while(slist != NULL)
    {
        tp = slist->content;
        ft_putnbr(tp->posx);
        ft_putchar('\n');
        ft_putnbr(tp->posy);
        ft_putchar('\n');
        ft_putnbr(tp->destx);
        ft_putchar('\n');
        ft_putnbr(tp->desty);
        ft_putchar('\n');
	slist = slist->next;
    }
}
