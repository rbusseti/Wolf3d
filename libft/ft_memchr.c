/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbusseti <rbusseti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 15:23:35 by rbusseti          #+#    #+#             */
/*   Updated: 2013/11/26 19:47:34 by rbusseti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		*stemp;

	stemp = (unsigned char *)s;
	while (n > 0)
	{
		if (*stemp != (unsigned char)c)
		{
			stemp++;
			n--;
		}
		else
			return (stemp);
	}
	return (NULL);
}
