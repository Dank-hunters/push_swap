/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 19:01:34 by cguiot            #+#    #+#             */
/*   Updated: 2021/10/14 19:27:23 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int is_here(int *value, int val, int pivot)
{
	int i;

	i = 0;
	while (i <= pivot)
	{
		if (value[i] == val)
			return (1);
		i++;
	}
	return (0);
}

int	found_next(t_list *stack, int pivot, int *value)
{
	t_elem *current;
	int val;

	current = stack->first;
	val = current->first;
	while (current != NULL)
	{
		if (is_here(value, current->value, pivot) == 1)
			current = current->next;
		else if (current->value <= val)
		{
			val = current->value;
			current = current->next;
		}
	}
	return (val);
}

void	found_piv(t_list *stack, int pivot)
{
	int *value;
	int i;

	i = 0;
	value = malloc(sizeof(int *) * pivot);
	ft_bzero(value, pivot);
	value[0] = found_lower(stack);
	while (i <= pivot)
	{
		value[i] = found_next(stack, pivot, value);
		i++;
	}
	dprintf(1, "la valeur du pivot : %i", value[pivot]);
}
