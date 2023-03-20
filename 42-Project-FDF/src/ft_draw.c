/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 14:58:09 by vokrut            #+#    #+#             */
/*   Updated: 2019/05/02 15:03:58 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void		ft_draw1(t_coord *coord)
{
	unsigned int	i;

	i = 0;
	while (i < coord->h - 1)
	{
		coord->xy1->x = coord->xyz_iso[i][coord->w - 1]->x;
		coord->xy1->y = coord->xyz_iso[i][coord->w - 1]->y;
		coord->xy2->x = coord->xyz_iso[i + 1][coord->w - 1]->x;
		coord->xy2->y = coord->xyz_iso[i + 1][coord->w - 1]->y;
		ft_draw_line(coord);
		i++;
	}
	i = 0;
	while (i < coord->w - 1)
	{
		coord->xy1->x = coord->xyz_iso[coord->h - 1][i]->x;
		coord->xy1->y = coord->xyz_iso[coord->h - 1][i]->y;
		coord->xy2->x = coord->xyz_iso[coord->h - 1][i + 1]->x;
		coord->xy2->y = coord->xyz_iso[coord->h - 1][i + 1]->y;
		ft_draw_line(coord);
		i++;
	}
}

void		ft_draw(t_coord *coord)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < coord->h - 1)
	{
		j = 0;
		while (j < coord->w - 1)
		{
			coord->xy1->x = coord->xyz_iso[i][j]->x;
			coord->xy1->y = coord->xyz_iso[i][j]->y;
			coord->xy2->x = coord->xyz_iso[i + 1][j]->x;
			coord->xy2->y = coord->xyz_iso[i + 1][j]->y;
			ft_draw_line(coord);
			coord->xy1->x = coord->xyz_iso[i][j]->x;
			coord->xy1->y = coord->xyz_iso[i][j]->y;
			coord->xy2->x = coord->xyz_iso[i][j + 1]->x;
			coord->xy2->y = coord->xyz_iso[i][j + 1]->y;
			ft_draw_line(coord);
			j++;
		}
		i++;
	}
	ft_draw1(coord);
}
