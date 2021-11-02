/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:37:33 by cguiot            #+#    #+#             */
/*   Updated: 2021/10/28 20:16:57 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	print_ext(int	inst)
{
	if (inst == 1)
		ft_putstr("pa\n");
	else if (inst == 2)
		ft_putstr("pb\n");
	else if (inst == 3)
		ft_putstr("ra\n");
	else if (inst == 4)
		ft_putstr("rb\n");
	else if (inst == 5)
		ft_putstr("sa\n");
	else if (inst == 6)
		ft_putstr("sb\n");
	else if (inst == 7)
		ft_putstr("ss\n");
	else if (inst == 8)
		ft_putstr("rr\n");
	else if (inst == 9)
		ft_putstr("rra\n");
	else if (inst == 10)
		ft_putstr("rrb\n");
	else if (inst == 11)
		ft_putstr("rrr\n");
	return (0);
}

int	ft_compare(int a, int b)
{
	if ((a == 3 && b == 4) || (a == 4 && b == 3))
		return (8);
	if ((a == 9 && b == 10) || (a == 10 && b == 9))
		return (11);
	return (0);
}


void	print_lst(t_liste_int	*lst)
{
	t_rot *current;

	current = lst->first;
	while (current != NULL)
	{
		print_ext(current->inst);
		current = current->next;
	}
	//free stack a/b et lst
	exit (0);
}

void	reduce_lst(t_liste_int	*lst)
{
	t_rot *current;

	current = lst->first;
	while (current != NULL && current->next != NULL)
	{
		if (ft_compare(current->inst, current->next->inst) > 0)
		{
			print_ext(ft_compare(current->inst, current->next->inst));
			current = current->next;
		}
		else
			print_ext(current->inst);
		current = current->next;
	}
	if (current->next == NULL && current != NULL)
		print_ext(current->inst);
	exit (0);
}