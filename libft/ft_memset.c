/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbusseti <rbusseti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 22:55:53 by rbusseti          #+#    #+#             */
/*   Updated: 2013/11/26 19:48:47 by rbusseti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	char			*snew;
	unsigned char	a;
	size_t			i;

	snew = (char *)s;
	a = c;
	i = 0;
	while (i < len)
	{
		snew[i] = a;
		i++;
	}
	return (s);
}
