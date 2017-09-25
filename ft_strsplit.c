/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 17:22:04 by dleong            #+#    #+#             */
/*   Updated: 2017/09/24 20:35:57 by dleong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define G(x) ft_memalloc(x)

char	**ft_strsplit(char const *s, char c)
{
	int		j[2];
	int		start;
	char	**r;

	r = NULL;
	if (s)
	{
		j[0] = -1;
		j[1] = -1;
		if (!(r = G(sizeof(char*) * ((int)ft_gc(s, c) + 1))))
			return (NULL);
		while (s[++j[0]] != '\0' && ++j[1] < (int)ft_gc(s, c))
		{
			while (s[j[0]] == c)
				j[0]++;
			start = j[0];
			while (s[j[0]] != c)
				j[0]++;
			if (!(r[j[1]] = G(sizeof(char) * ((int)ft_gl(s, c) + 1))))
				return (NULL);
			r[j[1]] = ft_strncpy(r[j[1]], (char *)&s[start], (j[0] - start));
		}
		r[j[1]] = NULL;
	}
	return (r);
}
