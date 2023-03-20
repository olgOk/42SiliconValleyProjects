/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 15:28:05 by vokrut            #+#    #+#             */
/*   Updated: 2019/05/02 15:32:59 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

t_line			*ft_add_line(t_line *arr, char *line)
{
	t_line		*fresh;
	t_line		*begin;

	if (!arr)
	{
		begin = (t_line *)malloc(sizeof(t_line));
		begin->next = NULL;
		begin->line = ft_strdup(line);
		return (begin);
	}
	fresh = (t_line *)malloc(sizeof(t_line));
	fresh->next = NULL;
	fresh->line = ft_strdup(line);
	begin = arr;
	while (arr->next)
		arr = arr->next;
	arr->next = fresh;
	return (begin);
}

t_line			*ft_read_file(int fd)
{
	char		*line;
	t_line		*arr;
	int			ret;

	arr = NULL;
	while ((ret = get_next_line(fd, &line) > 0))
	{
		arr = ft_add_line(arr, line);
		if (line)
			ft_strdel(&line);
	}
	return (arr);
}
