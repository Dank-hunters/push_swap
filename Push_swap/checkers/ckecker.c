/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ckecker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 15:57:35 by cguiot            #+#    #+#             */
/*   Updated: 2021/10/29 19:05:37 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "../include/push_swap.h"

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

void	read_inst()
{
	int ret;
	int	i;
	char *line;

	i = 0;
	ret = get_next_line(0, &line);
	while (ret == 1)
	{
		if (compare_inst(line) == 0)
			error(1);
		free(line);
		ret = get_next_line(0, &line);
	}
		free(line);
}

t_list	creat_stack(char **av)
{

}

void	checker(int ac, char **av)
{
	int	i;
	t_elem	*current;
	t_list	*stack;
	i = 0;
	read_inst();
	creat_stack(stack)
	use_inst(stack);
	sorted(stack);
}

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac == 1)
		error(0);
	checker(ac, av);
	return(0);
}
