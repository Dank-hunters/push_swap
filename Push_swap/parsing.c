/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:20:49 by cguiot            #+#    #+#             */
/*   Updated: 2021/10/21 21:03:36 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	isnum(char **str, int ac)
{
	int	i;
	int	y;

	i = 1;
	y = 0;
	while (i <= ac - 1)
	{
		if (str[i][0] == '\0')
			error(0);
		if (str[i][0] == '-' || str[i][0] == '+')
		{
			if (str[i][1] > '9' || str[i][1] < '0')
				error(0);
			y++;
		}
		while (str[i][y] != '\0')
		{
			if (str[i][y] < '0' || str[i][y] > '9')
				return (1);
			y++;
		}
		y = 0;
		i++;
	}
	return (0);
}

int	sorted(t_list *stack, int y)
{
	t_elem	*list;
	int		ty;
	int		i;

	ty = 0;
	i = 0;
	list = stack->first;
	while (i < stack->size - 1)
	{
		if (list->value > list->next->value)
			ty++;
		list = list->next;
		i++;
	}
	if (ty == 0 && y == 0)
		exit_prog(stack, 1);
	else if (ty == 0 && y != 0)
		return (1);
	return (0);
}

#include <stdio.h> //delete

int	compare(t_list *stack, int val)
{
	t_elem	*list;
	int		ty;

	ty = 0;
	list = stack->first;
	while (list != NULL)
	{
		if (val == list->value)
			ty++;
		list = list->next;
	}
	if (ty >= 2)
		exit_prog(stack, 0);
	return (0);
}

void	check_order(t_list *stack)
{
	t_elem	*list;
	int		i;

	i = 0;
	list = stack->first;
	while (list != NULL)
	{
		compare(stack, list->value);
		list = list->next;
	}
}
