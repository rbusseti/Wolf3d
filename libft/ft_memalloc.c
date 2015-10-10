/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbusseti <rbusseti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 16:43:23 by rbusseti          #+#    #+#             */
/*   Updated: 2013/11/26 23:00:51 by rbusseti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*str;

	if ((str = malloc(size)) == NULL)
		return (NULL);
	str = malloc(size);
	ft_bzero(str, size);
	return (str);
}
