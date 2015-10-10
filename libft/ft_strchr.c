/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbusseti <rbusseti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 18:24:21 by rbusseti          #+#    #+#             */
/*   Updated: 2013/11/26 19:49:34 by rbusseti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	a;
	int		i;

	a = c;
	i = 0;
	while (s[i] != a)
	{
		if (s[i] == '\0')
			return (NULL);
		i++;
	}
	if (s[i] == '\0')
		return ((char*)s + i);
	else
		return ((char *)s + i);
}
