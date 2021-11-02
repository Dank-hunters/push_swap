/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:01:16 by cguiot            #+#    #+#             */
/*   Updated: 2021/10/28 20:17:01 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	found_lower(t_list *stack)
{
	t_elem *current;
	int val;

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
void	first_sort(t_list *stack_a, t_list *stack_b, t_liste_int *inst, float percent)
{
	int i;
	int piv;
	int piv_b;
	int pos;
	t_elem *current;

	piv_b = 0;
	piv = 0;
	while (stack_a->size > 3 && sorted(stack_a, 5) == 0)
	{
		piv = found_piv_a(stack_a, (percent * stack_a->size));
		piv_b = found_piv_a(stack_a, ((percent * 0.5) * stack_a->size));
		pos = percent * stack_a->size;
		i = 0;
		while (i < pos)
		{
			current = stack_a->first;
			if (current->value <= piv)
			{
				push(stack_a, stack_b, inst, 2);
				if (stack_b->first->value <= piv_b)
					rotate(stack_b, inst,  4);
				i++;
			}
			else if (stack_a->last->value <= piv)
				reverse(stack_a, inst, 9);
			else 	
				rotate(stack_a, inst, 3);
		}
		if (percent < 0.5)
			percent += 0.0195;
	}
}

int	sort_tree(t_list *stack, t_liste_int *inst)
{
	t_elem *current;

	current = stack->first;
	if ( current->value < current->next->value &&
			current->next->value > current->next->next->value)
	{
		swap(stack, inst, 5);
		rotate(stack, inst, 3);
	}
	else if (current->value > current->next->value &&
			current->next->value < current->next->next->value && 
			current->value < current->next->next->value)
	{
		swap(stack, inst, 5);
	}
	else if (current->value > current->next->value &&
			current->next->value > current->next->next->value)
	{
		rotate(stack, inst, 3);
		rotate(stack, inst, 3);
	}
	else if (current->value < current->next->value &&
			current->next->value < current->next->next->value)
	{
		swap(stack, inst, 5);
		rotate(stack, inst, 3);
	}
	else if (current->value > current->next->value &&
			current->next->value < current->next->next->value && current->value > current->next->next->value )
	{
		rotate(stack, inst, 3);
	}
	else 
		return(0);
	return(0);
}

int	sort_five(t_list *stack_a, t_list *stack_b, t_liste_int *inst)
{
	int i;
	int u;
	t_elem *current;

	current = stack_a->first;
	u = 0;
	i = found_lower(stack_a);
	if (u == 0 && stack_a->last->value == i)
		reverse(stack_a, inst, 9);
	while (u <= 1)
	{
		current = stack_a->first;
		i = found_lower(stack_a);
		if (i == current->value)
		{
			push(stack_a, stack_b, inst, 2);
			u++;
		}
		else
			rotate(stack_a, inst, 3);
	}
	sort_tree(stack_a, inst);
	if (stack_b->first->value < stack_b->first->next->value)
		rotate(stack_b, inst, 4);
	push(stack_b, stack_a, inst, 1);
	push(stack_b, stack_a, inst, 1);
	return (0);
}

int		found_pos(t_list *stack, int i)
{
	int y;
	t_elem *current;

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

void	send_big(t_list *stack_a, t_list *stack_b, t_liste_int *inst)
{
	t_elem *current;
	int	i;
	int y;

	y = 0;
	i = 0;
	current = stack_b->first;
	while (stack_b->size != 0)
	{
		current = stack_b->first;
		i = found_hight(stack_b);
		y = found_pos(stack_b, i);
		if (current->value == i)
			push(stack_b, stack_a, inst, 1);
		else if (stack_b->first->next->value == i)
			swap(stack_b, inst, 6);
		else if (y <= stack_b->size * 0.5) 
			rotate(stack_b, inst, 4);
		else 
			reverse(stack_b, inst, 10); 
	}
}
