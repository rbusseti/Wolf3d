/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbusseti <rbusseti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 13:50:57 by rbusseti          #+#    #+#             */
/*   Updated: 2014/01/25 12:47:46 by rbusseti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	size_t	i;
	char	*s1temp;
	char	*s2temp;
	char	d;

	s1temp = (char *)s1;
	s2temp = (char *)s2;
	i = 0;
	d = c;
	while (i < n)
	{
		s1temp[i] = s2temp[i];
		if (s1temp[i] == d)
			return ((char *)s1 + i + 1);
		i++;
	}
	return (NULL);
}
