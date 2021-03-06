/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 14:16:35 by cguiot            #+#    #+#             */
/*   Updated: 2021/10/05 17:37:48 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(long long n)
{
	int		len;
	int		neg;
	long	nbr;
	char	*res;

	len = 1;
	neg = 0;
	if (n < 0)
		neg = 1;
	if (n < 0)
		n = n * -1;
	nbr = n;
	while (nbr >= 10 && ++len)
		nbr /= 10;
	if (new_malloc((void *)&res, sizeof(char), len + neg + 1) == 0)
		return (NULL);
	if (neg == 1)
		res[0] = '-';
	res[len + neg--] = '\0';
	while (len != 0)
	{
		res[len-- + neg] = n % 10 + '0';
		n /= 10;
	}
	return (res);
}
