/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 18:52:05 by cguiot            #+#    #+#             */
/*   Updated: 2021/11/03 14:39:01 by cguiot           ###   ########lyon.fr   */
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

typedef struct s_rot
{
	int				inst;
	struct s_rot	*next;
}				t_rot;

typedef struct s_list
{
	t_elem		*first;
	t_elem		*last;
	t_elem		*avlast;
	int			size;
	int			piv;
	int			pos;
}				t_list;

typedef struct s_list_int
{
	t_rot		*first;
	t_rot		*last;
	t_rot		*avlast;
	int			size;
}				t_liste_int;

void			add_list(t_liste_int *inst, int i);
void			sort_two(t_list *stack, t_liste_int *inst);
void			exit_progr(t_liste_int *stack, int i);
void			get_last(t_list *stack);
void			first_sort(t_list *stack_a, t_list *stack_b, \
					t_liste_int *inst, float pivot);
int				sort_tree(t_list *stack, t_liste_int *inst);
int				sort_five(t_list *stack_a, t_list *stack_b, \
					t_liste_int *inst, int u);
void			send_big(t_list *stack_a, t_list *stack_b, t_liste_int *inst);
int				found_lower(t_list *stack);
int				is_here(int *value, int val, int pivot);
int				found_next(t_list *stack, int pivot, int *value);
int				found_piv(t_list *stack, int pivot);
t_list			*create_b_stack(void);
int				found_piv_a(t_list *stack_a, int piv);
t_liste_int		*create_l_stack(void);
void			reduce_lst(t_liste_int	*lst, t_list *stack_a, t_list *stack_b);
int				found_hight(t_list *stack);
void			get_size(t_list *stack_a);
void			get_size_i(t_liste_int *stack_a);
void			*creat_rot(int content);
t_list			*create_b_stack(void);
void			exit_prog(t_list *stack, int i);
void			check_order(t_list *stack);
int				isnum(char **str, int ac);
int				sorted(t_list *stack, int y);
void			init_lst(t_list *list, char **av, int ac);
void			init_lst_b(t_list *list, int *t, int i);
t_list			*init_stack_b(int *v);
t_list			*init_stack_a(char **av);
void			*creat_elem(int content);
void			error(int i);
void			swap(t_list *stack_a, t_liste_int *inst, int i);
void			rotate(t_list *stack, t_liste_int *inst, int i);
void			push(t_list *stack_a, t_list *stack_b, \
					t_liste_int *inst, int i);
void			reverse(t_list *stack, t_liste_int *inst, int i);
#endif
