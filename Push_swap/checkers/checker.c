/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 15:57:35 by cguiot            #+#    #+#             */
/*   Updated: 2021/11/03 17:33:58 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	aff(t_list *stack_a)
{
	t_elem	*aff;
	int		i;

	i = 0;
	aff = stack_a->first;
	while (aff != NULL)
	{
		dprintf(1, "%i\n", aff->value);
		aff = aff->next;
		i++;
	}
	stack_a->size = i;
}

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

int	compare_inst(char *line)
{
	if (ft_strcmp(line, "pa") == 0)
		return (1);
	else if (ft_strcmp(line, "pb") == 0)
		return (1);
	else if (ft_strcmp(line, "sa") == 0)
		return (1);
	else if (ft_strcmp(line, "sb") == 0)
		return (1);
	else if (ft_strcmp(line, "ra") == 0)
		return (1);
	else if (ft_strcmp(line, "rb") == 0)
		return (1);
	else if (ft_strcmp(line, "rra") == 0)
		return (1);
	else if (ft_strcmp(line, "rrb") == 0)
		return (1);
	else if (ft_strcmp(line, "rrr") == 0)
		return (1);
	else if (ft_strcmp(line, "ss") == 0)
		return (1);
	else if (ft_strcmp(line, "rr") == 0)
		return (1);
	return (0);
}

void	normed(t_list *stack_a, t_list *stack_b, char *line)
{
	if (ft_strcmp(line, "rrr") == 0)
	{	
		reverse(stack_b);
		reverse(stack_a);
	}
	else if (ft_strcmp(line, "ss") == 0)
	{
		swap(stack_a);
		swap(stack_b);
	}
	else if (ft_strcmp(line, "rr") == 0)
	{
		rotate(stack_a);
		rotate(stack_b);
	}
}

void	exec(t_list *stack_a, t_list *stack_b, char *line)
{
	if (ft_strcmp(line, "pa") == 0)
		push(stack_b, stack_a);
	else if (ft_strcmp(line, "pb") == 0)
		push(stack_a, stack_b);
	else if (ft_strcmp(line, "sa") == 0)
		swap(stack_a);
	else if (ft_strcmp(line, "sb") == 0)
		swap(stack_b);
	else if (ft_strcmp(line, "ra") == 0)
		rotate(stack_a);
	else if (ft_strcmp(line, "rb") == 0)
		rotate(stack_b);
	else if (ft_strcmp(line, "rra") == 0)
		reverse(stack_a);
	else if (ft_strcmp(line, "rrb") == 0)
		reverse(stack_b);
	else
		normed(stack_a, stack_b, line);
}

void	read_inst(t_list *stack_a, t_list *stack_b)
{
	int		ret;
	int		i;
	char	*line;

	i = 0;
	ret = get_next_line(0, &line);
	while (ret == 1)
	{
		if (compare_inst(line) == 0)
			error(1);
		exec(stack_a, stack_b, line);
		free(line);
		ret = get_next_line(0, &line);
		i++;
	}
	free(line);
}

void	*creat_elem(int content)
{
	t_elem	*new;

	new = malloc(sizeof(*new));
	new->value = content;
	new->next = NULL;
	return (new);
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
	return (b_stack);
}

t_list	*init_stack(char **av)
{
	int		i;
	t_list	*stack_a;

	i = 1;
	stack_a = NULL;
	stack_a = malloc(sizeof(*stack_a));
	stack_a->size = 1;
	stack_a->first = creat_elem(ft_atol(av[1], 1));
	return (stack_a);
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
	list->size = i;
	current->next = NULL;
	list->last = current;
}

void	checker(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_b = create_b_stack();
	stack_a = init_stack(av);
	init_lst(stack_a, av, ac);
	if (sorted(stack_a, 5) == 1);
	{	
		ft_putstr("OK\n");
		exit(0);	
	}
	read_inst(stack_a, stack_b);
	if (sorted(stack_a, 5) == 1)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
}

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac == 1)
		error(0);
	checker(ac, av);
	return (0);
}
