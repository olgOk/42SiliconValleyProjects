/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 15:10:00 by vokrut            #+#    #+#             */
/*   Updated: 2019/05/02 15:12:37 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

unsigned int	ft_len_line(char *str)
{
	unsigned int	line_size;
	unsigned int	i;

	line_size = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		line_size++;
		while (str[i] && str[i] != ' ')
			i++;
	}
	return (line_size);
}

unsigned int	ft_list_size(t_line *arr)
{
	unsigned int	count;
	t_line			*tmp;

	tmp = arr;
	count = 0;
	while (tmp)
	{
		++count;
		tmp = tmp->next;
	}
	return (count);
}
