/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbusseti <rbusseti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 21:57:46 by rbusseti          #+#    #+#             */
/*   Updated: 2013/11/26 23:00:22 by rbusseti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	if ((str = malloc(sizeof(char) * size)) == NULL)
		return (NULL);
	str = malloc(sizeof(char) * size);
	str = ft_memset(str, 0, size);
	return (str);
}
