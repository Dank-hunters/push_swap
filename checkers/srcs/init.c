/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:50:16 by cguiot            #+#    #+#             */
/*   Updated: 2021/11/16 17:24:07 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strcmp(char *s1, char *s2)
{
	size_t			i;

	i = 0;
	while (s1 || s2)
	{
		if (s1[i] != s2[i])
			return (1);
		if (s1[i] == '\0')
			return (0);
		i++;
	}
	return (0);
}

void	*creat_eleme(int content)
{
	t_eleme	*new;

	new = malloc(sizeof(*new));
	new->value = content;
	new->next = NULL;
	return (new);
}

t_lists	creat_b_stack(void)
{
	t_lists		b_stack;

	b_stack.first = NULL;
	b_stack.last = NULL;
	b_stack.size = 0;
	return (b_stack);
}

t_lists	init_stackk(char **av)
{
	int		i;
	t_lists	stack_a;

	i = 1;
	stack_a.size = 1;
	stack_a.first = creat_eleme(ft_atol(av[1], 1));
	return (stack_a);
}

void	inite_lst(t_lists *list, char **av, int ac)
{
	int		i;
	t_eleme	*new;
	t_eleme	*current;

	i = 2;
	current = list->first;
	while (i <= ac - 1)
	{
		new = creat_eleme(ft_atol(av[i], 1));
		current->next = new;
		current = current->next;
		if (i == ac - 2)
			list->avlast = current;
		i++;
	}
	list->size = i;
	current->next = NULL;
	list->last = current;
}
