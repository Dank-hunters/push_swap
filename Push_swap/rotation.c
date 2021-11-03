/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:29:20 by cguiot            #+#    #+#             */
/*   Updated: 2021/11/03 14:28:07 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	swap(t_list *stack, t_liste_int *inst, int i)
{
	t_elem	*current;
	t_elem	*tmp;

	if (stack->size < 2)
		return ;
	tmp = NULL;
	tmp = stack->first->next->next;
	current = stack->first->next;
	current->next = stack->first;
	current->next->next = tmp;
	stack->first = current;
	get_last(stack);
	get_size(stack);
	add_list(inst, i);
}

void	get_last(t_list *stack)
{
	t_elem	*current;

	current = stack->first;
	stack->last = NULL;
	while (current != NULL)
	{
		if (current->next != NULL)
		{
			if (stack->size > 1 && current->next->next == NULL)
				stack->avlast = current;
		}
		stack->last = current;
		current = current->next;
	}
}

void	push(t_list *stack, t_list *stack_r, t_liste_int *inst, int i)
{
	t_elem	*tmp;

	if (stack->size == 0)
		return ;
	tmp = stack->first->next;
	stack->first->next = stack_r->first;
	stack_r->first = stack->first;
	stack->first = tmp;
	get_last(stack);
	get_last(stack_r);
	get_size(stack);
	get_size(stack_r);
	add_list(inst, i);
}

void	rotate(t_list *stack, t_liste_int *inst, int i)
{
	t_elem	*tmp;

	if (stack->size <= 1)
		return ;
	tmp = stack->first->next;
	stack->first->next = NULL;
	stack->last->next = stack->first;
	stack->first = tmp;
	get_last(stack);
	get_size(stack);
	add_list(inst, i);
}

void	reverse(t_list *stack, t_liste_int *inst, int i)
{
	if (stack->size <= 1)
		return ;
	stack->avlast->next = NULL;
	stack->last->next = stack->first;
	stack->first = stack->last;
	get_size(stack);
	get_last(stack);
	add_list(inst, i);
}
