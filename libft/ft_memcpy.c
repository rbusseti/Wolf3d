/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbusseti <rbusseti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 20:43:17 by rbusseti          #+#    #+#             */
/*   Updated: 2014/01/25 12:45:44 by rbusseti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*s1temp;
	char	*s2temp;

	s1temp = (char *)s1;
	s2temp = (char *)s2;
	i = 0;
	while (i < n)
	{
		s1temp[i] = s2temp[i];
		i++;
	}
	return (s1);
}
