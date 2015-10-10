/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbusseti <rbusseti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:38:51 by rbusseti          #+#    #+#             */
/*   Updated: 2014/10/12 17:35:11 by rbusseti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char const *str)
{
	int		n;
	char	*str2;

	n = ft_strlen(str);
	if (!(str2 = malloc(sizeof(char) * (n + 1))))
		return (NULL);
	n = 0;
	while (str[n] != '\0')
	{
		str2[n] = str[n];
		n++;
	}
	str2[n] = '\0';
	return (str2);
}
