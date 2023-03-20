/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 20:56:02 by vokrut            #+#    #+#             */
/*   Updated: 2019/03/20 14:16:34 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list	*ft_add(t_list *list, char **arr)
{
	t_list		*fresh;
	t_list		*begin;

	if (!list)
	{
		begin = (t_list *)malloc(sizeof(t_list));
		begin->next = NULL;
		begin->tetr_arr = arr;
		begin->symbol = 'A';
		return (begin);
	}
	fresh = (t_list *)malloc(sizeof(t_list));
	fresh->next = NULL;
	fresh->tetr_arr = arr;
	begin = list;
	while (list->next)
		list = list->next;
	list->next = fresh;
	fresh->symbol = list->symbol + 1;
	return (begin);
}

int		ft_list_size(t_list *list)
{
	int		count;
	t_list	*tmp;

	count = 0;
	tmp = list;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

int		ft_map_size(int n)
{
	int		size;
	int		k;

	size = 2;
	k = 4 * n;
	while (size * size < k)
		size++;
	return (size);
}

char	**ft_create_map(int size)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	map = (char **)malloc(sizeof(char *) * (size + 1));
	while (i < size)
	{
		j = 0;
		map[i] = (char *)malloc(sizeof(char) * (size + 1));
		while (j < size)
			map[i][j++] = '.';
		map[i][j] = '\0';
		i++;
	}
	map[i] = NULL;
	return (map);
}
