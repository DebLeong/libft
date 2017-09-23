/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleong <dleong@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 21:12:01 by dleong            #+#    #+#             */
/*   Updated: 2017/09/20 23:55:16 by dleong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"
#include "string.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int	i;
	int	j;
	int	curr;

	i = 0;
	j = 0;
	if ((int)ft_strlen(little) == 0)
		return ((char *)big);
	if (big == little)
		return ((char *)&big[0]);
	while (big[i] != '\0' && i < (int)len - 1)
	{
		curr = i;
		while (little[j] != '\0' && big[i] == little[j])
		{
			i++;
			j++;
			if (j == (int)ft_strlen(little) - 1)
				return ((char *)&big[curr]);
			break ;
		}
		i = curr + 1;
		j = 0;
	}
	return (NULL);
}
