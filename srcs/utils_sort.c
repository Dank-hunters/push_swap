/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <cguiot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:01:16 by cguiot            #+#    #+#             */
/*   Updated: 2021/11/16 17:21:46 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	normed(t_liste_int *inst, t_list *stacka, int val)
{
	if (val <= stacka->piv)
		reverse(stacka, inst, 9);
	else
		rotate(stacka, inst, 3);
}

void	first_sort(t_list *stacka, t_list *stackb, t_liste_int *inst, float pt)
{
	int		i;
	t_elem	*current;

	while (stacka->size > 3 && sorted(stacka, 5) == 0)
	{
		stacka->piv = found_piv_a(stacka, (pt * stacka->size));
		stackb->piv = found_piv_a(stacka, ((pt * 0.5) * stacka->size));
		stacka->pos = pt * stacka->size;
		i = 0;
		while (i < stacka->pos)
		{
			current = stacka->first;
			if (current->value <= stacka->piv)
			{
				push(stacka, stackb, inst, 2);
				if (stackb->first->value <= stackb->piv)
					rotate(stackb, inst, 4);
				i++;
			}
			else
				normed(inst, stacka, stacka->last->value);
		}
		if (pt < 0.5)
			pt += 0.0195;
	}
}

int	sort_tree_next(t_list *stack, t_liste_int *inst)
{
	t_elem	*current;

	current = stack->first;
	if (current->value > current->next->value && \
			current->next->value > current->next->next->value)
	{
		swap(stack, inst, 5);
		reverse(stack, inst, 9);
	}
	else if (current->value < current->next->value && \
			current->next->value < current->next->next->value)
	{
		swap(stack, inst, 5);
		rotate(stack, inst, 3);
	}
	else if (current->value > current->next->value && \
			current->next->value < current->next->next->value && \
			current->value > current->next->next->value)
	{
		rotate(stack, inst, 3);
	}
	else
		return (0);
	return (0);
}

int	sort_tree(t_list *stack, t_liste_int *inst)
{
	t_elem	*current;

	current = stack->first;
	if (current->value < current->next->value && \
			current->next->value > current->next->next->value && \
			current->value < current->next->next->value)
	{
		swap(stack, inst, 5);
		rotate(stack, inst, 3);
	}
	else if (current->value > current->next->value && \
			current->next->value < current->next->next->value && \
			current->value < current->next->next->value)
	{
		swap(stack, inst, 5);
	}
	else if (current->value < current->next->value && \
			current->next->value > current->next->next->value && \
			current->value > current->next->next->value)
	{
		reverse(stack, inst, 9);
	}
	else
		return (sort_tree_next(stack, inst));
	return (0);
}

int	sort_five(t_list *stacka, t_list *stackb, t_liste_int *inst, int u)
{
	int		i;
	t_elem	*current;

	current = stacka->first;
	i = found_lower(stacka);
	if (u == 0 && stacka->last->value == i)
		reverse(stacka, inst, 9);
	while (u <= 1)
	{
		current = stacka->first;
		i = found_lower(stacka);
		if (i == current->value)
		{
			push(stacka, stackb, inst, 2);
			u++;
		}
		else
			rotate(stacka, inst, 3);
	}
	sort_tree(stacka, inst);
	if (stackb->first->value < stackb->first->next->value)
		rotate(stackb, inst, 4);
	push(stackb, stacka, inst, 1);
	push(stackb, stacka, inst, 1);
	return (0);
}
