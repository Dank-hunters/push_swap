/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cguiot <cguiot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 15:54:37 by cguiot            #+#    #+#             */
/*   Updated: 2021/10/29 18:47:20 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	build(char **line, char **save)
{
	int	i;

	i = 0;
	while (line[0] && line[0][i])
	{
		if (line[0][i] == '\n')
		{
			line[0][i] = '\0';
			i++;
			*save = ft_strdupp(line[0] + i, 0);
			if (save == NULL)
				return (-1);
			*line = ft_strdupp(line[0], 1);
			if (line == NULL)
				return (-1);
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_free(char **str, int ret)
{
	if (!(*str == NULL))
	{
		free(str);
		*str = NULL;
	}
	return (ret);
}

int	get_next_line(int fd, char **line)
{
	static char	*save = NULL;
	char		buff[1 + 1];
	int			ret;

	*line = NULL;
	ret = 1;
	if (fd < 0 || line == NULL)
		return (-1);
	if (save)
	{
		*line = ft_strdupp(save, 1);
		save = NULL;
	}
	while (ret > 0 && (build(line, &save) == 0))
	{
		ret = read(fd, buff, 1);
		if (ret == -1)
			return (ft_free(&save, -1));
		buff[ret] = '\0';
		*line = ft_strjoin(*line, buff);
		if (*line == NULL)
			return (ft_free(line, -1));
	}
	return (ret);
}
