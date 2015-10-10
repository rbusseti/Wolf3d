#include "libft.h"

t_list	*ft_create_elem(void *content)
{
    t_list	*new;

    if (!(new = malloc(sizeof(*new))))
	return (NULL);
    new->prev = NULL;
    new->next = NULL;
    new->content = content;
    return (new);
}
