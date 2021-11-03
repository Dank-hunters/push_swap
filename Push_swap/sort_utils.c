/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:02:25 by cguiot            #+#    #+#             */
/*   Updated: 2021/11/03 14:28:08 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	found_hight(t_list *stack)
{
	int		i;
	t_elem	*current;

	current = stack->first;
	get_size(stack);
	i = current->value;
	if (stack->size == 0)
		return (i);
	while (current != NULL)
	{
		current = current->next;
		if (current != NULL && i < current->value)
		{
			i = current->value;
		}
	}
	return (i);
}

int	found_lower(t_list *stack)
{
	t_elem	*current;
	int		val;

	val = 0;
	current = stack->first;
	val = current->value;
	while (current != NULL)
	{
		if (val >= current->value)
			val = current->value;
		current = current->next;
	}
	return (val);
}

int	found_pos(t_list *stack, int i)
{
	int		y;
	t_elem	*current;

	current = stack->first;
	y = 0;
	while (current != NULL)
	{
		if (i == current->value)
			return (y);
		y++;
		current = current->next;
	}
	return (-1);
}

void	send_big(t_list *stacka, t_list *stackb, t_liste_int *inst)
{
	t_elem	*current;
	int		i;
	int		y;

	y = 0;
	i = 0;
	current = stackb->first;
	while (stackb->size != 0)
	{
		current = stackb->first;
		i = found_hight(stackb);
		y = found_pos(stackb, i);
		if (current->value == i)
			push(stackb, stacka, inst, 1);
		else if (stackb->first->next->value == i)
			swap(stackb, inst, 6);
		else if (y <= stackb->size * 0.5)
			rotate(stackb, inst, 4);
		else
			reverse(stackb, inst, 10);
	}
}

void	sort_two(t_list *stack, t_liste_int *inst)
{
	if (stack->first->value > stack->first->next->value)
		swap(stack, inst, 5);
}
