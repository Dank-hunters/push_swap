/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 19:07:26 by cguiot            #+#    #+#             */
/*   Updated: 2021/10/28 20:17:35 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>


int	check_arg(int ac, char **av)
{
	if (ac == 1 || ac == 2)
		error(0);
	if (isnum(av, ac) != 0)
		error(0);
	return (0);
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
void	get_size_i(t_liste_int *stack_a)
{
	t_rot	*aff;
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

int	found_hight(t_list *stack)
{
	int i;
	t_elem *current;

	current = stack->first;
	get_size(stack);
	i = current->value;
	if (stack->size == 0)
		return (i);
	while (current != NULL)
	{
		current = current->next;
		if (current!= NULL && i < current->value)
		{
			i = current->value;
		}
	}
	return (i);
}


void	sort_two(t_list *stack, t_liste_int *inst)
{
	if (stack->first->value > stack->first->next->value)
		swap(stack, inst, 5);
}

void	push_swap(t_list *stack_a, t_liste_int *inst)
{
	float percent;
	int piv;
	t_list *stack_b;

	piv = 0;
	stack_b = create_b_stack();
	if (stack_a->size == 5)
		sort_five(stack_a, stack_b, inst);
	else
	{
		percent = 0.13123;
		if (stack_a->size < 200)
			percent = percent * 3;
		first_sort(stack_a, stack_b, inst, percent);
		if (stack_a->size == 3 && sorted(stack_a, 5) == 0)
			sort_tree(stack_a, inst);
		else if (stack_a->size == 2 && sorted(stack_a, 5) == 0)
			sort_two(stack_a, inst);
		send_big(stack_a, stack_b, inst);
	}
	reduce_lst(inst);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_liste_int	*inst;


	if (check_arg(ac, av) == 1)
		return (0);
	inst = create_l_stack();
	stack_a = init_stack_a(av);
	init_lst(stack_a, av, ac);
	check_order(stack_a);
	get_size(stack_a);
	sorted(stack_a, 0);
	push_swap(stack_a, inst);
	ft_putstr("algo run\n");
	if (sorted(stack_a, 5) == 1)
		dprintf(1, "c trier fdp");
	exit(0);
	return (0);
}
