/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbusseti <rbusseti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 13:50:26 by rbusseti          #+#    #+#             */
/*   Updated: 2013/12/06 02:26:13 by rbusseti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*strnew;
	size_t		i;

	if ((strnew = malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	i = 0;
	while ((i < len) && (s[start + i] != '\0'))
	{
		strnew[i] = s[start + i];
		i++;
	}
	strnew[i] = '\0';
	return (strnew);
}
