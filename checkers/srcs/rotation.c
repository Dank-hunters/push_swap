/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:17:26 by cguiot            #+#    #+#             */
/*   Updated: 2021/11/05 16:24:42 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	get_laste(t_lists *stack)
{
	t_eleme	*current;

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

void	swapp(t_lists *stack)
{
	t_eleme	*current;
	t_eleme	*tmp;

	if (stack->size < 2)
		return ;
	tmp = NULL;
	tmp = stack->first->next->next;
	current = stack->first->next;
	current->next = stack->first;
	current->next->next = tmp;
	stack->first = current;
	get_laste(stack);
	get_sizee(stack);
}

void	pushh(t_lists *stack, t_lists *stack_r)
{
	t_eleme	*tmp;

	if (stack->size == 0)
		return ;
	tmp = stack->first->next;
	stack->first->next = stack_r->first;
	stack_r->first = stack->first;
	stack->first = tmp;
	get_laste(stack);
	get_laste(stack_r);
	get_sizee(stack);
	get_sizee(stack_r);
}

void	rotatee(t_lists *stack)
{
	t_eleme	*tmp;

	if (stack->size <= 1)
		return ;
	tmp = stack->first->next;
	stack->first->next = NULL;
	stack->last->next = stack->first;
	stack->first = tmp;
	get_laste(stack);
	get_sizee(stack);
}

void	reversee(t_lists *stack)
{
	if (stack->size <= 1)
		return ;
	stack->avlast->next = NULL;
	stack->last->next = stack->first;
	stack->first = stack->last;
	get_sizee(stack);
	get_laste(stack);
}
