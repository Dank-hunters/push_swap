/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 14:19:58 by cguiot            #+#    #+#             */
/*   Updated: 2021/10/08 15:53:25 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_liste	*ft_lstmap(t_liste *lst, void *(*f)(void *), void (*del)(void *))
{
	t_liste	*liste;
	t_liste	*new;
	t_liste	*pliste;

	liste = NULL;
	pliste = lst;
	while (lst)
	{
		new = ft_lstnew((*f)(lst->content));
		if (!new)
		{
			ft_lstclear(&pliste, (*del));
			return (0);
		}
		ft_lstadd_back(&liste, new);
		lst = lst->next;
	}
	return (liste);
}
