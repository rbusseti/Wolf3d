/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_gnl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbusseti <rbusseti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 19:07:04 by rbusseti          #+#    #+#             */
/*   Updated: 2014/01/22 19:44:43 by rbusseti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strdup_gnl(const char *str)
{
	size_t		i;
	char		*cpy;

	i = 0;
	if (!(cpy = malloc((ft_strlen(str) + 1) * sizeof(char))))
		return (NULL);
	while (str[i] && str[i] != '\n')
	{
		cpy[i] = str[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
