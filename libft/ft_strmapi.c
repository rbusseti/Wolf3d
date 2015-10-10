/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbusseti <rbusseti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 12:22:07 by rbusseti          #+#    #+#             */
/*   Updated: 2014/10/12 17:36:26 by rbusseti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		j;
	char	*strnew;

	i = 0;
	j = ft_strlen(s);
	strnew = malloc(sizeof(char) * (j + 1));
	while (i < j)
	{
		strnew[i] = (*f)(i, s[i]);
		i++;
	}
	strnew[i] = '\0';
	return (strnew);
}
