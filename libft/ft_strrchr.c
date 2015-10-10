/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbusseti <rbusseti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 20:40:00 by rbusseti          #+#    #+#             */
/*   Updated: 2013/11/27 21:33:01 by rbusseti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char const *s, int c)
{
	int		len;
	char	a;

	len = ft_strlen(s);
	a = c;
	while (s[len] != a)
	{
		if (len == 0)
			return (NULL);
		len--;
	}
	return ((char *)s + len);
}
