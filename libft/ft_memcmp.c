/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbusseti <rbusseti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 17:55:00 by rbusseti          #+#    #+#             */
/*   Updated: 2014/01/25 12:48:23 by rbusseti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*tmp1;
	char	*tmp2;
	size_t	i;

	tmp1 = (char *)s1;
	tmp2 = (char *)s2;
	i = 0;
	while (i < n)
	{
		if (tmp1[i] == tmp2[i])
			i++;
		else
			return ((unsigned char)tmp1[i] - (unsigned char)tmp2[i]);
	}
	return (0);
}
