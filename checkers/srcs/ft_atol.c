/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:19:38 by cguiot            #+#    #+#             */
/*   Updated: 2021/11/16 17:42:18 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	test(int nb, int pn)
{
	if ((nb * pn) > 2147483647 || (nb * pn) < -2147483648)
	{
		ft_putstr("Error\n");
		exit(0);
	}
}

static int	check(int tmp, long int nb, long int pn)
{
	if ((nb < tmp) && (pn == -1))
		return (0);
	else if (nb < tmp && pn == 1)
		return (-1);
	return (1);
}

long long int	ft_atol(const char *str, int pn)
{
	long long int	nb;
	long int		tmp;

	tmp = 0;
	nb = 0;
	while ((*str == ' ') || (*str > 8 && *str < 14))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			pn = pn * -1;
		str++;
	}
	while ((*str >= '0') && (*str <= '9'))
	{
		nb = (nb * 10) + *str++ - 48;
		if (check(tmp, nb, pn) == -1)
			return (-1);
		if (check(tmp, nb, pn) == 0)
			return (0);
		tmp = nb;
	}
	test(nb, pn);
	return ((int)(nb * pn));
}

void	exit_p(t_lists *stack)
{
	t_eleme	*list;
	t_eleme	*tmp;

	list = NULL;
	tmp = stack->first;
	while (tmp != NULL)
	{
		list = tmp;
		tmp = list->next;
		if (list)
			free(list);
	}
}
