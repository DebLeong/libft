/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 15:48:08 by dleong            #+#    #+#             */
/*   Updated: 2017/09/23 15:54:18 by dleong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int	result;

	if (!s1 || !s2 || !n)
		return (0);
	result = ft_strncmp(s1, s2, n);
	if (result == 0)
		return (1);
	return (0);
}
