/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 13:17:55 by dleong            #+#    #+#             */
/*   Updated: 2017/09/24 17:20:51 by dleong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		i;
	int		len;
	char	*a;

	i = 0;
	len = ft_getdigit(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (!(a = ft_strnew(sizeof(char) * len)))
		return (NULL);
	if (n < 0)
	{
		a[i] = '-';
		n = -n;
		i++;
	}
	while (len > i)
	{
		a[len - 1] = (n % 10) + '0';
		n = n / 10;
		len--;
	}
	return (a);
}
