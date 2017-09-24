/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 17:22:04 by dleong            #+#    #+#             */
/*   Updated: 2017/09/24 13:15:37 by dleong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	int		i;
	int		k;
	int		start;
	char	**result;

	if (!s || !c)
		return (NULL);
	i = -1;
	k = -1;
	if (!(result = ft_strnew(sizeof(char*) * ft_getstrcount(s, c))))
		return (NULL);
	while (s[++i] != '\0' && ++k < ft_getstrcount(s, c))
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] != c)
			i++;
		if (!(result[k] = ft_strnew(sizeof(char) * (size_t)ft_getstrlen(s, c))))
			return (NULL);
		result[k] = ft_strncpy(result[k], (char *)&s[start], (i - start));
	}
	result[k] = NULL;
	return (result);
}
