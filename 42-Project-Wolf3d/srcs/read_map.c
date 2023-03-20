/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 20:02:03 by knaumov           #+#    #+#             */
/*   Updated: 2019/08/31 21:16:13 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		copy_int_from_string_element(char *line, int **array)
{
	int		index;

	index = 0;
	while (*line)
	{
		(*array)[index++] = ft_atoi(line);
		while (*line >= '0' && *line <= '9')
			++line;
		if (*line == ' ')
			++line;
	}
}

int			find_number_of_int(char *line, t_list **list)
{
	int		width;

	width = 0;
	while (*line)
	{
		if (*line < '0' || *line > '9')
		{
			delete_list(list);
			error("Invalid map");
		}
		while (*line >= '0' && *line <= '9')
			++line;
		++width;
		if (*line == ' ')
			++line;
	}
	return (width);
}

void		print_int_matrix(int **matrix, int width)
{
	int		i;
	int		j;

	i = 0;
	while (matrix[i])
	{
		j = 0;
		while (j < width)
		{
			ft_printf("%2d ", matrix[i][j]);
			++j;
		}
		ft_printf("\n");
		++i;
	}
}

int			**list_to_matrix(t_info *info, t_list **list)
{
	int		**matrix;
	int		tmp;
	t_list	*index;

	matrix = (int **)malloc(sizeof(int *) * (size_list(*list) + 1));
	info->map_x = find_number_of_int((*list)->line, list);
	info->map_y = 0;
	index = (*list);
	while (index)
	{
		tmp = find_number_of_int(index->line, list);
		if (tmp != info->map_x)
		{
			delete_list(list);
			error("Invalid map");
		}
		matrix[info->map_y] = (int *)malloc(sizeof(int) * info->map_x);
		copy_int_from_string_element(index->line, &matrix[info->map_y++]);
		index = index->next;
	}
	matrix[info->map_y] = NULL;
	return (matrix);
}

void		read_map(t_info *info, int fd)
{
	char	*line;
	t_list	*input;

	line = NULL;
	input = NULL;
	while (get_next_line(fd, &line) == 1)
	{
		if (ft_strcmp("", line))
			input = add_list_back(input, line);
		ft_strdel(&line);
	}
	info->map = list_to_matrix(info, &input);
	delete_list(&input);
}
