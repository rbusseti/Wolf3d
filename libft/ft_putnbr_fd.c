/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbusseti <rbusseti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 15:36:57 by rbusseti          #+#    #+#             */
/*   Updated: 2014/01/25 13:17:25 by rbusseti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		i;

	i = n % 10;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = n * (-1);
	}
	if (n < 10)
		ft_putchar_fd(n + '0', fd);
	else
	{
		n = n / 10;
		ft_putnbr_fd(n, fd);
		ft_putchar_fd(i + '0', fd);
	}
}
