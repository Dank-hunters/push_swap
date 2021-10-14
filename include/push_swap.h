/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 18:52:05 by cguiot            #+#    #+#             */
/*   Updated: 2021/10/13 18:08:44 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../dependency/libft/libft.h"

typedef struct s_elem
{
	int					value;
	struct s_elem		*next;
	struct s_elem		*prev;
}				t_elem;

typedef struct s_list
{
	t_elem		*first;
	t_elem		*last;
	t_elem		*avlast;
	int			size;
}				t_list;



void			exit_prog(t_list *stack, int i);
void			check_order(t_list *stack);
int				isnum(char **str, int ac);
int				sorted(t_list *stack);
long long int	ft_atol(const char *str, int pn);
void			init_lst(t_list *list, char **av, int ac);
void			init_lst_b(t_list *list, int *t, int i);
t_list			*init_stack_b(int *v);
t_list			*init_stack_a(char **av);
t_elem			*creat_elem(int content);
void			error(int i);
void			swap(t_list *stack_a);
void		    rotate(t_list *stack);
void			push(t_list *stack_a, t_list *stack_b);
void			ss(t_list *stack_a, t_list *stack_b);
void			reverse(t_list *stack);
#endif
