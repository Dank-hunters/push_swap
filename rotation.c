/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:29:20 by cguiot            #+#    #+#             */
/*   Updated: 2021/10/12 18:26:17 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	swap(t_list *stack)
{
	t_elem	*current;
	t_elem	*tmp;

	tmp = NULL;
	tmp = stack->first->next->next;
	current = stack->first->next;
	current->next = stack->first;
	current->next->next = tmp;
	stack->first = current;
	ft_putstr("\nsa active\n");
}

void	ss(t_list *stack_a, t_list *stack_b)
{
	swap(stack_a);
	swap(stack_b);
}

void	push(t_list *stack, t_list *stack_r)
{
	t_elem	*current;
	t_elem	*current_r;
	t_elem	*tmp;

	tmp = NULL;
	current = stack->first;
	current_r = stack_r->first;
	stack_r->first = stack->first;
	stack->first = current_r;
	tmp = stack->first->next;
	stack->first->next = stack_r->first->next;
	stack_r->first->next = tmp;
	ft_putstr("\npush\n");
}

void	rotate(t_list *stack)
{
	t_elem	*tmp;

	tmp = NULL;
	tmp = stack->first->next;
	stack->first->next = NULL;
	stack->last->next = stack->first;
	stack->first = tmp;
	ft_putstr("\nrotate\n");
}

void	reverse(t_list *stack)
{
	stack->avlast->next = NULL;
	stack->last->next = stack->first;
	stack->first = stack->last;
	ft_putstr("\nreverse\n");
}
