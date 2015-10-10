/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbusseti <rbusseti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 18:20:07 by rbusseti          #+#    #+#             */
/*   Updated: 2013/11/28 12:45:53 by rbusseti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(char const *s1, char const *s2)
{
	int		i;
	size_t	j;
	size_t	k;

	j = ft_strlen(s1) + 1;
	k = ft_strlen(s2) + 1;
	if (j >= k)
		i = ft_strncmp(s1, s2, j);
	else
		i = ft_strncmp(s1, s2, k);
	return (i);
}
