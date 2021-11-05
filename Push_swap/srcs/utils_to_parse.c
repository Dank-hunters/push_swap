/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_to_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 19:08:23 by cguiot            #+#    #+#             */
/*   Updated: 2021/11/03 14:28:06 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	error(int i)
{
	i++;
	ft_putstr("Error\n");
	exit (0);
}

void	exit_prog(t_list *stack, int i)
{
	t_elem	*list;
	t_elem	*tmp;

	list = NULL;
	tmp = stack->first;
	while (tmp != NULL)
	{
		list = tmp;
		tmp = list->next;
		if (list)
			free(list);
	}
	if (i == 0)
		ft_putstr("Error\n");
	if (i != 15)
		exit (0);
}

void	exit_progr(t_liste_int *stack, int i)
{
	t_rot	*list;
	t_rot	*tmp;

	list = NULL;
	tmp = stack->first;
	while (tmp != NULL)
	{
		list = tmp;
		tmp = list->next;
		if (list)
			free(list);
	}
	if (i == 0)
		ft_putstr("Error\n");
	if (i != 15)
		exit (0);
}
