/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:14:33 by cguiot            #+#    #+#             */
/*   Updated: 2021/10/12 19:28:29 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_list	*init_stack_b(int *v)
{
	t_list	*stack_b;

	stack_b = NULL;
	stack_b = malloc(sizeof(*stack_b));
	stack_b->first = creat_elem(v[0]);
	return (stack_b);
}

t_list	*init_stack_a(char **av)
{
	int		i;
	t_list	*stack_a;	

	i = 1;
	stack_a = NULL;
	stack_a = malloc(sizeof(*stack_a));
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
	list->last = current;
	list->last->next = NULL;
}

t_elem	*creat_elem(int content)
{
	t_elem	*new;

	new = malloc(sizeof(*new));
	new->value = content;
	new->next = NULL;
	return (new);
}
