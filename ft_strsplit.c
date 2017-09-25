/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 17:22:04 by dleong            #+#    #+#             */
/*   Updated: 2017/09/24 22:30:28 by dleong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define G(x) ft_memalloc(x)

static void	ft_free(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		free(s[i++]);
	free(s);
}

char		**ft_strsplit(char const *s, char c)
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
			if (!(r[j[1]] = ft_strsub((char *)s, a, j[0] - (size_t)a)))
				ft_free(r);
		}
		r[j[1]] = NULL;
	}
	return (r);
}
