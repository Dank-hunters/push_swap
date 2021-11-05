/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 16:01:40 by cguiot            #+#    #+#             */
/*   Updated: 2021/11/05 16:24:44 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_sorted(t_lists *stack, int y)
{
	t_eleme	*list;
	int		ty;
	int		i;

	ty = 0;
	i = 0;
	list = stack->first;
	while (list->next != NULL)
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
		ft_putstr("Error\n");
	exit (0);
}

void	get_sizee(t_lists *stack_a)
{
	t_eleme	*aff;
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
