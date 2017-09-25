/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 17:22:04 by dleong            #+#    #+#             */
/*   Updated: 2017/09/25 13:23:16 by dleong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char    **ptrptr;
	int     cw;
	int     i;
	ptrptr = NULL;
	if (s)
	{
		i = 0;
		cw = ft_gc(s, c);
		ptrptr = (char **)malloc((sizeof(char *) * cw) + 1);
		if (!ptrptr)
			return (NULL);
		while (cw--)
		{
			while (*s == c && *s != '\0')
				s++;
			ptrptr[i] = ft_strsub(s, 0, ft_gl(s, c));
			if (!ptrptr[i])
				return (NULL);
			s = s + ft_gl(s, c);
			i++;
		}
		ptrptr[i] = NULL;
	}
	return (ptrptr);
}
