/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbusseti <rbusseti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 19:20:33 by rbusseti          #+#    #+#             */
/*   Updated: 2014/01/25 13:06:51 by rbusseti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		j;

	if (ft_strlen((char *)s2) == 0)
		return ((char *)s1);
	if (ft_strlen((char *)s2) > n)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] && n > 0)
	{
		while ((s1[i] == s2[j]) && (s2[j]))
		{
			i++;
			j++;
		}
		if (ft_strlen((char *)s2) == j)
			return ((char *)(s1 + i - j));
		else
			i = i - j + 1;
		j = 0;
		n--;
	}
	return (NULL);
}
