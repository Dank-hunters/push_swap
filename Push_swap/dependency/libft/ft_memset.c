/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 14:57:24 by cguiot            #+#    #+#             */
/*   Updated: 2020/11/24 13:40:48 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	int				i;
	unsigned char	*sv;

	sv = s;
	i = 0;
	while (n)
	{
		sv[i] = c;
		i++;
		n--;
	}
	return (s);
}