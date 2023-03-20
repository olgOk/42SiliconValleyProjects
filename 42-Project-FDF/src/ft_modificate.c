/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modificate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 15:23:00 by vokrut            #+#    #+#             */
/*   Updated: 2019/05/02 15:26:33 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void		ft_modificate(t_line *arr, t_coord *coord)
{
	t_line			*tmp;
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	tmp = arr;
	i = 0;
	while (tmp)
	{
		j = 0;
		k = 0;
		coord->coord[i] = (int *)malloc(sizeof(int) * coord->w);
		while (j < coord->w)
		{
			coord->coord[i][j] = ft_atoi(&tmp->line[k]);
			while (tmp->line[k] && tmp->line[k] != ' ')
				k++;
			while (tmp->line[k] && tmp->line[k] == ' ')
				k++;
			j++;
		}
		i++;
		tmp = tmp->next;
	}
}
