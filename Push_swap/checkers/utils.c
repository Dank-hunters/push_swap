/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 16:01:40 by cguiot            #+#    #+#             */
/*   Updated: 2021/11/03 16:59:11 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
	if (ty == 0 && y != 0)
		return (1);
	return (0);
}

void	error(int i)
{
	if (i == 0)
		exit (0);
	if (i == 1)
		ft_putstr("error\n");
	exit (0);
}

void	get_size(t_list *stack_a)
{
	t_elem	*aff;
	int		i;

	i = 0;
	aff = stack_a->first;
	while (aff != NULL)
	{
		aff = aff->next;
		i++;
	}
	stack_a->size = i;
}
