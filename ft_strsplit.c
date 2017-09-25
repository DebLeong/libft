/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 17:22:04 by dleong            #+#    #+#             */
/*   Updated: 2017/09/25 13:08:35 by dleong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define G(x) ft_memalloc(x)

char				**ft_strsplit(char const *s, char c)
{
	size_t			j[2];
	unsigned int	a;
	char			**r;

	r = NULL;
	if (s)
	{
		j[0] = -1;
		j[1] = -1;
		if (!(r = (char **)G(sizeof(char*) * (ft_gc(s, c) + 1))))
			return (NULL);
		while (s[++j[0]] != '\0' && ++j[1] < (size_t)ft_gc(s, c))
		{
			while (s[j[0]] == c)
				j[0]++;
			a = j[0];
			while (s[j[0]] != c)
				j[0]++;
			if (!(r[j[1]] = (char *)ft_strsub((char *)s, a, ft_gl(&s[a], c))))
				ft_memdel((void**)r);
		}
		r[j[1]] = NULL;
	}
	return (r);
}
