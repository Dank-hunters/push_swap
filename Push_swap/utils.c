/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:17:31 by cguiot            #+#    #+#             */
/*   Updated: 2021/10/28 20:17:00 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

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
	if ((nb * pn) > 2147483647 || (nb * pn) < -2147483648)
		error(0);
	return ((int)(nb * pn));
}

void	exit_prog(t_list *stack, int i)
{
	t_elem	*list;
	t_elem	*tmp;

	list = NULL;
	tmp = stack->first;
	while (tmp != NULL)
	{
		list = tmp;
		tmp = list->next;
		if (list)
			free(list);
	}
	if (i == 0)
		ft_putstr("Error\n");
	exit (0);
}

int	get_next(t_list *stack, int pivot)
{
	t_elem *current;
//	int		tmp;
	int		i;

	current = stack->first;
	i = found_hight(stack);
	while (current != NULL)
	{
		if (current->value > pivot && current->value < i)
			i = current->value;
		current = current->next;
	}
	return (i);
}	

int	found_piv_a(t_list *stack, int piv)
{
	int	pivot;
	int	i;

	i = 1;
	pivot = found_lower(stack);
	while (i < piv)
	{
		pivot = get_next(stack, pivot);
		i++;
	}
	return (pivot);
}