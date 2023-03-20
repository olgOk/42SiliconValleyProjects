/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 12:54:13 by vokrut            #+#    #+#             */
/*   Updated: 2019/03/19 20:02:53 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_colcmp(char **arr, const int index)
{
	int i;

	i = 0;
	while (arr[i])
	{
		if (arr[i][index] != '.')
			return (0);
		i++;
	}
	return (1);
}

static t_list	*ft_rmdots_row(t_list *tetr)
{
	int		i;
	int		j;
	int		count;
	char	**arr;
	t_list	*new_tetr;

	new_tetr = NULL;
	while (tetr)
	{
		i = -1;
		j = 0;
		count = 0;
		while (tetr->tetr_arr[++i])
			if (ft_strcmp(tetr->tetr_arr[i], "...."))
				count++;
		arr = (char **)malloc(sizeof(char *) * (count + 1));
		arr[count] = NULL;
		i = -1;
		while (++i < 4)
			if (ft_strcmp(tetr->tetr_arr[i], "...."))
				arr[j++] = ft_strdup(tetr->tetr_arr[i]);
		new_tetr = ft_add(new_tetr, arr);
		tetr = tetr->next;
	}
	return (new_tetr);
}

static char		**ft_update(char **arr, int i, int start)
{
	int		j;
	char	*tmp;

	j = 0;
	while (j < i)
	{
		tmp = ft_strsub(arr[j], start, (ft_strlen(arr[j]) - 1));
		free(arr[j]);
		arr[j] = tmp;
		j++;
	}
	return (arr);
}

static t_list	*ft_rmdots_col(t_list *tetr)
{
	int		k;
	int		i;
	t_list	*begin;

	begin = tetr;
	while (tetr)
	{
		i = 0;
		while (tetr->tetr_arr[i])
			i++;
		k = 0;
		while (k++ <= 2)
			if (ft_colcmp(tetr->tetr_arr, 0))
				tetr->tetr_arr = ft_update(tetr->tetr_arr, i, 1);
		while (--k >= 1)
			if (ft_colcmp(tetr->tetr_arr, ft_strlen(tetr->tetr_arr[0]) - 1))
				tetr->tetr_arr = ft_update(tetr->tetr_arr, i, 0);
		tetr = tetr->next;
	}
	return (begin);
}

t_list			*ft_cleaning(t_list *tetr)
{
	tetr = ft_rmdots_row(tetr);
	tetr = ft_rmdots_col(tetr);
	return (tetr);
}
