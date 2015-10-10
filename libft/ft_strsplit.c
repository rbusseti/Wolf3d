/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbusseti <rbusseti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 19:41:10 by rbusseti          #+#    #+#             */
/*   Updated: 2014/10/12 17:37:07 by rbusseti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**create_string(char **strnew, char const *s, char c)
{
	unsigned int	i;
	int				k;
	size_t			len;

	i = 0;
	k = 0;
	len = 0;
	while (s[i] != '\0')
	{
		while ((s[i] != c) && (s[i] != '\0'))
		{
			len++;
			i++;
			if ((s[i] == c) || (s[i] == '\0'))
			{
				strnew[k] = ft_strsub(s, (size_t)i - len, len);
				k++;
				len = 0;
			}
		}
		if (s[i] != '\0')
			i++;
	}
	strnew[k] = '\0';
	return (strnew);
}

char		**ft_strsplit(char const *s, char c)
{
	int				i;
	int				nbstr;
	char			**strnew;

	i = 0;
	nbstr = 0;
	if (s[0] != c)
		nbstr++;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			if ((s[i + 1] != c) && (s[i + 1] != '\0'))
				nbstr++;
		}
		i++;
	}
	if ((strnew = malloc(sizeof(char *) * (nbstr + 1))) == NULL)
		return (NULL);
	return (create_string(strnew, s, c));
}
