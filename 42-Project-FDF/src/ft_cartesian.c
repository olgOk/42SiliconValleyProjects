/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cartesian.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 11:45:20 by vokrut            #+#    #+#             */
/*   Updated: 2019/05/02 16:55:08 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void		ft_cartesian(t_coord *coord)
{
	unsigned int	i;
	unsigned int	j;

	coord->xyz_cart = malloc(sizeof(t_cart*) * (coord->h + 1));
	coord->xyz_cart[coord->h] = NULL;
	i = 0;
	while (i < coord->h)
	{
		coord->xyz_cart[i] = malloc(sizeof(t_cart) * (coord->w + 1));
		j = 0;
		while (j < coord->w)
		{
			coord->xyz_cart[i][j] = malloc(sizeof(t_cart));
			coord->xyz_cart[i][j]->z = coord->coord[i][j];
			coord->xyz_cart[i][j]->x = (j + 1) * 30;
			coord->xyz_cart[i][j]->y = (i + 1) * 30;
			j++;
		}
		i++;
	}
}
