/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbusseti <rbusseti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 17:06:34 by rbusseti          #+#    #+#             */
/*   Updated: 2014/01/25 12:59:19 by rbusseti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	l;

	i = ft_strlen(dst);
	j = ft_strlen(src);
	l = 0;
	k = i + j;
	if (size >= i)
	{
		while (i < (size - 1))
		{
			dst[i] = src[l];
			i++;
			l++;
		}
		dst[i] = '\0';
		return (k);
	}
	return (size + j);
}
