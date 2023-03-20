/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 20:45:30 by vokrut            #+#    #+#             */
/*   Updated: 2019/03/18 11:46:24 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	int		ft_check_placement(char **map, char **shape, int mx, int my)
{
	int		sx;
	int		sy;

	sy = 0;
	while (shape[sy])
	{
		sx = 0;
		if (map[my + sy] == 0)
			return (0);
		while (shape[sy][sx])
		{
			if (map[my + sy][mx + sx] == 0)
				return (0);
			if (map[my + sy][mx + sx] != '.' && shape[sy][sx] != '.')
				return (0);
			sx++;
		}
		sy++;
	}
	return (1);
}

static	char	**ft_place(char **map, t_list *tetr, int mx, int my)
{
	int		arrx;
	int		arry;

	arry = 0;
	while (tetr->tetr_arr[arry])
	{
		arrx = 0;
		while (tetr->tetr_arr[arry][arrx])
		{
			if (tetr->tetr_arr[arry][arrx] != '.')
				map[my + arry][mx + arrx] = tetr->symbol;
			arrx++;
		}
		arry++;
	}
	return (map);
}

static char		**ft_remove(char **map, t_list *tetr, int mx, int my)
{
	int		arrx;
	int		arry;

	arry = 0;
	while (tetr->tetr_arr[arry])
	{
		arrx = 0;
		while (tetr->tetr_arr[arry][arrx])
		{
			if (tetr->tetr_arr[arry][arrx] != '.')
				map[my + arry][mx + arrx] = '.';
			arrx++;
		}
		arry++;
	}
	return (map);
}

int				ft_algorithm(char **map, t_list *tetr)
{
	int		mx;
	int		my;

	if (!tetr)
		return (1);
	my = 0;
	while (map[my])
	{
		mx = 0;
		while (map[my][mx])
		{
			if (ft_check_placement(map, tetr->tetr_arr, mx, my))
			{
				map = ft_place(map, tetr, mx, my);
				if (!ft_algorithm(map, tetr->next))
					map = ft_remove(map, tetr, mx, my);
				else
					return (1);
			}
			mx++;
		}
		my++;
	}
	return (0);
}
