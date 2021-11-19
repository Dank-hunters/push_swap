/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 15:57:35 by cguiot            #+#    #+#             */
/*   Updated: 2021/11/16 17:42:01 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

void	normed(t_lists *stack_a, t_lists *stack_b, char *line)
{
	if (ft_strcmp(line, "rrr") == 0)
	{	
		reversee(stack_b);
		reversee(stack_a);
	}
	else if (ft_strcmp(line, "ss") == 0)
	{
		swapp(stack_a);
		swapp(stack_b);
	}
	else if (ft_strcmp(line, "rr") == 0)
	{
		rotatee(stack_a);
		rotatee(stack_b);
	}
}

void	exec(t_lists *stack_a, t_lists *stack_b, char *line)
{
	if (ft_strcmp(line, "pa") == 0)
		pushh(stack_b, stack_a);
	else if (ft_strcmp(line, "pb") == 0)
		pushh(stack_a, stack_b);
	else if (ft_strcmp(line, "sa") == 0)
		swapp(stack_a);
	else if (ft_strcmp(line, "sb") == 0)
		swapp(stack_b);
	else if (ft_strcmp(line, "ra") == 0)
		rotatee(stack_a);
	else if (ft_strcmp(line, "rb") == 0)
		rotatee(stack_b);
	else if (ft_strcmp(line, "rra") == 0)
		reversee(stack_a);
	else if (ft_strcmp(line, "rrb") == 0)
		reversee(stack_b);
	else
		normed(stack_a, stack_b, line);
}

void	read_inst(t_lists *stack_a, t_lists *stack_b)
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

void	checker(int ac, char **av)
{
	t_lists	stack_a;
	t_lists	stack_b;

	stack_b = creat_b_stack();
	stack_a = init_stackk(av);
	inite_lst(&stack_a, av, ac);
	read_inst(&stack_a, &stack_b);
	if (ft_sorted(&stack_a, 5) == 1)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	exit_p(&stack_a);
	exit_p(&stack_b);
}
