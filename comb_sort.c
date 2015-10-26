#include "wolf3d.h"

void	ft_swap(int *is_swap, int size, int inter, t_sprite **sprite)
{
    int		i;
    t_sprite	*swap;

    i = 0;
    while (i <= size - inter)
    {
	if ((sprite[i])->dist < (sprite[i + inter])->dist)
	{
	    swap = sprite[i];
	    sprite[i] = sprite[i + inter];
	    sprite[i + inter] = swap;
	    *is_swap = 1;
	}
	i++;
    }
}

void	ft_comb_sort(t_sprite **sprite, int size)
{
    int	    inter;
    int	    swap;

    inter = size;
    swap = 0;
    while (inter > 1 || swap != 0)
    {
	inter = inter / 1.3;
	if (inter < 1)
	    inter = 1;
	swap = 0;
	ft_swap(&swap, size, inter, sprite);
    }
}
