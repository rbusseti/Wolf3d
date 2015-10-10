/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbusseti <rbusseti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 14:20:38 by rbusseti          #+#    #+#             */
/*   Updated: 2013/11/30 18:21:33 by rbusseti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	int		i;

	if (n < 0)
	{
		ft_putchar('-');
		n = n * (-1);
	}
	i = n % 10;
	if (n < 10)
		ft_putchar(i + '0');
	else
	{
		n = n / 10;
		ft_putnbr(n);
		ft_putchar(i + '0');
	}
}
