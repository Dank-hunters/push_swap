/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 14:20:36 by cguiot            #+#    #+#             */
/*   Updated: 2021/10/08 15:53:36 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_liste	*ft_lstnew(void *content)
{
	t_liste	*new;

	new = malloc(sizeof(t_liste));
	if (!(new))
		return (0);
	new->content = content;
	new->next = NULL;
	return (new);
}
