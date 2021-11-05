/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 15:40:26 by cguiot            #+#    #+#             */
/*   Updated: 2021/11/03 14:21:54 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stddef.h>

typedef struct s_liste
{
	void			*content;
	struct s_liste	*next;
}				t_liste;

long long int		ft_atol(const char *str, int pn);
int					new_malloc(void **dst, int type, int len);
int					new_ternaire(int condition, int res1, int res2);
void				ft_putchar(char c);
void				ft_putstr(char *str);
int					ft_atoi(const char *str);
void				ft_bzero(void *s, int n);
void				*ft_calloc(size_t ne, size_t size);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
char				*ft_itoa(long long n);
void				ft_lstadd_back(t_liste **alst, t_liste *nw);
void				ft_lstadd_front(t_liste **alst, t_liste *nw);
void				ft_lstclear(t_liste **lst, void (*del)(void*));
void				ft_lstdelone(t_liste *lst, void (*del)(void*));
void				ft_lstiter(t_liste *lst, void (*f)(void *));
t_liste				*ft_lstlast(t_liste *lst);
t_liste				*ft_lstmap(t_liste *lst, void *(*f)(void *),
						void (*del)(void *));
t_liste				*ft_lstnew(void *content);
int					ft_lstsize(t_liste *lst);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memset(void *s, int c, size_t n);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbr(int n);
void				ft_putstr_fd(char *s, int fd);
char				**ft_split(char const *s, char c);
char				*ft_strchr(const char *s, int c);
char				*ft_strdup(const char *src);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
size_t				ft_strlen(const char *str);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *to_find, const char *str, size_t n);
char				*ft_strrchr(const char *s, int c);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_substr(char const *s, unsigned int start, size_t len);
int					ft_toupper(int c);
int					ft_tolower(int c);

#endif
