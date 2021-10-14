/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 19:07:26 by cguiot            #+#    #+#             */
/*   Updated: 2021/10/14 17:34:52 by cguiot           ###   ########lyon.fr   */
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
	while (i == 0 || aff != NULL)
	{
		dprintf(1, "%i\n", aff->value);
		aff = aff->next;
		i++;
	}
	stack_a->size = i;
	dprintf(1, "\n\n%i\n\n", stack_a->size);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	
	if (check_arg(ac, av) == 1)
		return (0);
	stack_a = init_stack_a(av);
	init_lst(stack_a, av, ac);
	check_order(stack_a);
	get_size(stack_a);
	sorted(stack_a);
	ft_putstr("algo run");
	exit(0);
	return (0);
}
