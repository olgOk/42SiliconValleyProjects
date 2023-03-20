/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 15:04:12 by vokrut            #+#    #+#             */
/*   Updated: 2019/05/02 15:09:46 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void		ft_free_coord(t_coord *coord)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < coord->h)
	{
		j = 0;
		while (j < coord->w)
		{
			free(coord->xyz_cart[i][j]);
			free(coord->xyz_iso[i][j]);
			j++;
		}
		free(coord->xyz_cart[i]);
		free(coord->xyz_iso[i]);
		free(coord->coord[i]);
		i++;
	}
	free(coord->xyz_cart);
	free(coord->xyz_iso);
	free(coord->color);
	free(coord->xy1);
	free(coord->xy2);
	free(coord->coord);
}

void		ft_free_list(t_line *arr)
{
	t_line		*tmp;

	while (arr)
	{
		tmp = arr;
		arr = arr->next;
		free(arr->line);
		free(tmp);
	}
	arr = NULL;
}

void		ft_free(t_coord *coord)
{
	ft_free_coord(coord);
}
