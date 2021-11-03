/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:17:31 by cguiot            #+#    #+#             */
/*   Updated: 2021/11/03 14:28:04 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	add_list(t_liste_int *inst, int i)
{
	t_rot	*current;
	t_rot	*new;

	new = creat_rot(i);
	inst->size++;
	if (inst->first == NULL)
		inst->first = new;
	else
	{
		current = inst->first;
		while (current->next != NULL)
			current = current->next;
		current->next = new;
	}
	get_size_i(inst);
}

int	get_next(t_list *stack, int pivot)
{
	t_elem	*current;
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

void	*creat_elem(int content)
{
	t_elem	*new;

	new = malloc(sizeof(*new));
	new->value = content;
	new->next = NULL;
	return (new);
}

void	*creat_rot(int content)
{
	t_rot	*new;

	new = malloc(sizeof(*new));
	new->inst = content;
	new->next = NULL;
	return (new);
}
