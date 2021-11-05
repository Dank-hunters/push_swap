/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:14:33 by cguiot            #+#    #+#             */
/*   Updated: 2021/11/03 14:28:02 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_list	*init_stack_a(char **av)
{
	int		i;
	t_list	*stack_a;	

	i = 1;
	stack_a = NULL;
	stack_a = malloc(sizeof(*stack_a));
	stack_a->piv = 0;
	stack_a->pos = 0;
	stack_a->size = 1;
	stack_a->first = creat_elem(ft_atol(av[1], 1));
	return (stack_a);
}

void	init_lst_b(t_list *list, int *t, int i)
{	
	int		u;
	t_elem	*new;
	t_elem	*current;

	u = 1;
	current = list->first;
	while (u <= i - 1)
	{
		new = creat_elem(t[u]);
		current->prev = current;
		current->next = new;
		current = current->next;
		u++;
	}
	current->next = NULL;
	list->last = current;
	list->last->next = NULL;
}

void	init_lst(t_list *list, char **av, int ac)
{
	int		i;
	t_elem	*new;
	t_elem	*current;

	i = 2;
	current = list->first;
	while (i <= ac - 1)
	{
		new = creat_elem(ft_atol(av[i], 1));
		current->next = new;
		current = current->next;
		if (i == ac - 2)
			list->avlast = current;
		i++;
	}
	current->next = NULL;
	list->last = current;
}

t_list	*create_b_stack(void)
{
	t_list		*b_stack;

	b_stack = malloc(sizeof(*b_stack));
	if (b_stack == NULL)
		return (NULL);
	b_stack->first = NULL;
	b_stack->last = NULL;
	b_stack->size = 0;
	b_stack->piv = 0;
	return (b_stack);
}

t_liste_int	*create_l_stack(void)
{
	t_liste_int		*b_stack;

	b_stack = malloc(sizeof(*b_stack));
	if (b_stack == NULL)
		return (NULL);
	b_stack->first = NULL;
	b_stack->last = NULL;
	b_stack->size = 0;
	return (b_stack);
}
