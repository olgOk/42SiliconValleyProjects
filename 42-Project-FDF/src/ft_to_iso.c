/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_iso.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 15:33:23 by vokrut            #+#    #+#             */
/*   Updated: 2019/05/02 15:37:51 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void				ft_to_iso(t_coord *coord)
{
	unsigned int	i;
	unsigned int	j;
	int				x;
	int				y;
	int				z;

	coord->xyz_iso = malloc(sizeof(t_iso*) * (coord->h + 1));
	coord->xyz_iso[coord->h] = NULL;
	i = 0;
	while (i < coord->h)
	{
		coord->xyz_iso[i] = malloc(sizeof(t_iso) * (coord->w + 1));
		j = 0;
		while (j < coord->w)
		{
			coord->xyz_iso[i][j] = malloc(sizeof(t_iso));
			x = coord->xyz_cart[i][j]->x;
			y = coord->xyz_cart[i][j]->y;
			z = coord->xyz_cart[i][j]->z;
			coord->xyz_iso[i][j]->x = 400 + (x - y) * cos(coord->an);
			coord->xyz_iso[i][j]->y = 150 - z * 8.0 + (x + y) * sin(coord->an);
			j++;
		}
		i++;
	}
}
