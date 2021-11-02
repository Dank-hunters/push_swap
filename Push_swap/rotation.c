/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:29:20 by cguiot            #+#    #+#             */
/*   Updated: 2021/10/26 16:07:22 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>


void	add_list(t_liste_int *inst, int i)
{
	t_rot	*current;
	t_rot	*new;

	new  = creat_rot(i);
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

void	delete_element(t_elem *e)
{
	if (e)
	{
		free(e);
		e = NULL;
	}

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
/*
int	push(t_list *sender, t_list *receiver)
{
	t_elem	*tmp;
	
	if (sender->size == 0)
		return (0);
	dprintf(1, "\nici\n");
	tmp = receiver->first;
	receiver->first = creat_elem(sender->first->value);
	receiver->first->next = tmp;
	tmp = sender->first;
	receiver->size++;
	sender->first = sender->first->next;
	//delete_element(tmp);
	sender->size--;
	get_size(sender);

	ft_putstr("stack b :\n");
	get_size(receiver);
	get_last(sender);
	get_last(receiver);
	return (1);
}

*/
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
