/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 10:06:56 by vokrut            #+#    #+#             */
/*   Updated: 2019/03/20 18:07:03 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				ft_check_symbol(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '#' && str[i] != '.')
			return (0);
		i++;
	}
	return (1);
}

static	char	*ft_copy_line(char *line, char *old_line)
{
	char		*str;
	int			i;

	free(old_line);
	i = 0;
	str = ft_strnew(5);
	while (line[i])
	{
		str[i] = line[i];
		++i;
	}
	return (str);
}

static	int		ft_tetrcpy(int fd, t_list **list)
{
	char	*line;
	char	**arr;
	int		j;
	int		ret;

	if ((ret = get_next_line(fd, &line)) == 0)
		return (-1);
	arr = NULL;
	arr = ft_create_arr(arr);
	j = -1;
	while (++j < 4)
	{
		if ((ret = ft_check_line(line, arr)) == -1)
			return (-1);
		arr[j] = ft_copy_line(line, arr[j]);
		if (line)
			ft_strdel(&line);
		ret = get_next_line(fd, &line);
		if (ft_check1(ret, j, arr) == -1)
			return (-1);
	}
	(*list) = ft_add(*list, arr);
	if (ft_check2(ret, line) == -1)
		return (-1);
	return ((ret == 0) ? 0 : 1);
}

static	int		ft_check_tetr(t_list *tetr)
{
	int		count_hash;
	int		conn;
	int		i;
	int		j;

	conn = 0;
	count_hash = 0;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (tetr->tetr_arr[i][j] == '#')
			{
				conn += (i > 0 && tetr->tetr_arr[i - 1][j] == '#') ? 1 : 0;
				conn += (j > 0 && tetr->tetr_arr[i][j - 1] == '#') ? 1 : 0;
				conn += (i < 3 && tetr->tetr_arr[i + 1][j] == '#') ? 1 : 0;
				conn += (j < 3 && tetr->tetr_arr[i][j + 1] == '#') ? 1 : 0;
				count_hash++;
			}
		}
	}
	return (count_hash == 4 && (conn == 6 || conn == 8) ? 1 : 0);
}

t_list			*ft_valid_input(int fd)
{
	t_list	*list;
	t_list	*tmp;
	int		result;

	list = NULL;
	if (fd < 0)
		return (NULL);
	while ((result = ft_tetrcpy(fd, &list)))
		if (result == -1)
		{
			ft_free_list(list);
			return (NULL);
		}
	tmp = list;
	while (tmp)
	{
		if (!ft_check_tetr(tmp))
		{
			ft_free_list(list);
			return (NULL);
		}
		tmp = tmp->next;
	}
	return (list);
}
