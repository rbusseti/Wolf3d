/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbusseti <rbusseti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/08 16:12:52 by rbusseti          #+#    #+#             */
/*   Updated: 2014/10/12 17:35:52 by rbusseti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_char(char const *str, char c)
{
	int		i;
	char	*strnew;
	char	*temp;

	i = ft_strlen(str);
	strnew = malloc(sizeof(char) * (i + 2));
	i = 0;
	if (str[i] != '\0')
	{
		while (str[i] != '\0')
		{
			strnew[i] = str[i];
			i++;
		}
	}
	strnew[i] = c;
	i++;
	strnew[i] = '\0';
	temp = strnew;
	free(strnew);
	return (temp);
}
