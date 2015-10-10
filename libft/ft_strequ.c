/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbusseti <rbusseti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 12:47:57 by rbusseti          #+#    #+#             */
/*   Updated: 2014/01/25 12:53:53 by rbusseti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int		i;
	size_t	j;
	size_t	k;

	j = ft_strlen(s1) + 1;
	k = ft_strlen(s2) + 1;
	if (j >= k)
		i = ft_strnequ(s1, s2, j);
	else
		i = ft_strnequ(s1, s2, k);
	return (i);
}
