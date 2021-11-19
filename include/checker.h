/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 16:21:49 by cguiot            #+#    #+#             */
/*   Updated: 2021/11/16 17:41:39 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <../include/push_swap.h>

typedef struct s_eleme
{
	int				value;
	struct s_eleme	*next;
	struct s_eleme	*prev;
}				t_eleme;

typedef struct s_lists
{
	t_eleme	*first;
	t_eleme	*last;
	t_eleme	*avlast;
	int		size;
}				t_lists;

t_lists			creat_b_stack(void);
t_lists			init_stackk(char **av);
void			checker(int ac, char **av);
void			inite_lst(t_lists *list, char **av, int ac);
int				ft_strcmp(char *s1, char *s2);
void			error(int i);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strdupp(const char *s1, int leaks);
int				get_next_line(int fd, char **line);
void			ft_putstr(char *str);

void			swapp(t_lists *stack);
void			pushh(t_lists *stack, t_lists *stack_r);
void			rotatee(t_lists *stack);
void			reversee(t_lists *stack);
long long int	ft_atol(const char *str, int pn);

int				ft_sorted(t_lists *stack, int y);
void			get_laste(t_lists *stack);
void			get_sizee(t_lists *stack);
void			*creat_eleme(int content);

void			exit_p(t_lists *stack);
#endif
