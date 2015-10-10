#include "libft.h"

int	ft_list_push_back(t_list **list, void *content)
{
    t_list	*temp;
    t_list	*new;

    temp = *list;
    if (temp == NULL)
    {
	if (!(*list = ft_create_elem(content)))
	    return (-1);
	else
	    return (0);
    }
    if (!(new = ft_create_elem(content)))
	return (-1);
    while (temp->next)
	temp = temp->next;
    temp->next = new;
    new->prev = temp;
    return (1);
}
