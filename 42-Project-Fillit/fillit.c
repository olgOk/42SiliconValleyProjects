/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 09:36:05 by vokrut            #+#    #+#             */
/*   Updated: 2019/03/20 19:33:20 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "fillit.h"

void	ft_free_map(char **map, int size)
{
	while (size >= 0)
	{
		if (map[size])
			free(map[size]);
		--size;
	}
	free(map);
}

void	ft_print_solution(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		ft_putstr(map[i]);
		ft_putchar('\n');
		i++;
	}
}

void	ft_free_list(t_list *list)
{
	int		i;
	int		arrlen;
	t_list	*temp;

	while (list)
	{
		temp = list;
		list = list->next;
		arrlen = 0;
		while (temp->tetr_arr[arrlen])
			arrlen++;
		i = -1;
		while (++i < arrlen)
			free(temp->tetr_arr[i]);
		free(temp->tetr_arr);
		free(temp);
	}
	list = NULL;
}

void	ft_additional(t_list *list)
{
	int		size;
	char	**map;

	list = ft_cleaning(list);
	size = ft_map_size(ft_list_size(list));
	map = ft_create_map(size);
	while (!ft_algorithm(map, list))
	{
		ft_free_map(map, size);
		map = ft_create_map(++size);
	}
	ft_print_solution(map);
	ft_free_list(list);
	ft_free_map(map, size);
}

int		main(int argc, char **argv)
{
	int		fd;
	t_list	*list;

	if (argc != 2)
	{
		ft_putstr("Usage: ./fillit [name_of_file]\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (!(list = ft_valid_input(fd)))
	{
		ft_putstr("error\n");
		close(fd);
		return (0);
	}
	ft_additional(list);
	close(fd);
	ft_free_list(list);
	return (0);
}
