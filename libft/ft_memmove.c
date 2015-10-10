/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbusseti <rbusseti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 01:07:50 by rbusseti          #+#    #+#             */
/*   Updated: 2013/11/26 19:48:34 by rbusseti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	char	*stemp1;
	char	*stemp2;

	stemp1 = (char *)s1;
	stemp2 = (char *)s2;
	if (s2 < s1)
	{
		while (n > 0)
		{
			stemp1[n - 1] = stemp2[n - 1];
			n--;
		}
	}
	else
		stemp1 = ft_memcpy(s1, s2, n);
	return (s1);
}
