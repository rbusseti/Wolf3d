/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbusseti <rbusseti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 13:42:42 by rbusseti          #+#    #+#             */
/*   Updated: 2014/10/12 17:34:47 by rbusseti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*calc_itoa(int n, int i, char *strnew)
{
	int		mod;

	if (n < 0)
	{
		n = n * (-1);
		strnew[0] = '-';
	}
	while (n > 9)
	{
		i--;
		mod = n % 10;
		n = n / 10;
		strnew[i] = mod + '0';
	}
	strnew[i - 1] = n + '0';
	return (strnew);
}

char	*ft_itoa(int n)
{
	char	*strnew;
	int		i;
	int		nsave;

	i = 1;
	nsave = n;
	if (n < 0)
	{
		n = n * (-1);
		i++;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	if ((strnew = malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	strnew = malloc(sizeof(char) * (i + 1));
	strnew = calc_itoa(nsave, i, strnew);
	return (strnew);
}
