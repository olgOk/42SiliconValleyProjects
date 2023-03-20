/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additionalsec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 17:59:50 by vokrut            #+#    #+#             */
/*   Updated: 2019/03/20 18:07:29 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char			**ft_create_arr(char **arr)
{
	int	j;

	j = 0;
	arr = (char **)malloc(sizeof(char *) * 5);
	arr[4] = NULL;
	while (j < 4)
		arr[j++] = ft_strnew(5);
	return (arr);
}

int				ft_check_line(char *line, char **arr)
{
	if (ft_strlen(line) != 4 || !ft_check_symbol(line))
	{
		ft_free_map(arr, 3);
		if (line)
			ft_strdel(&line);
		return (-1);
	}
	return (1);
}

int				ft_check1(int ret, int j, char **arr)
{
	if (ret == 0 && j != 3)
	{
		ft_free_map(arr, 3);
		return (-1);
	}
	return (1);
}

int				ft_check2(int ret, char *line)
{
	if ((ret == 1) && ft_strcmp(line, ""))
	{
		free(line);
		return (-1);
	}
	if (ret > 0)
		free(line);
	return (1);
}
