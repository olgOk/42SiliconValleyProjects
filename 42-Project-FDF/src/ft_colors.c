/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 11:53:39 by vokrut            #+#    #+#             */
/*   Updated: 2019/05/02 16:54:06 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

static int		ft_get_light(int start, int end, double percent)
{
	return ((int)((1.0 - percent) * start + percent * end));
}

static	double	ft_percent(double start, double end, double current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? (1.0) : (placement / distance));
}

int				ft_color_grad(t_coord *coord, double dx, double dy, t_point *xy)
{
	int		r;
	int		g;
	int		b;
	double	percent;

	if (dx > dy)
		percent = ft_percent(coord->xy1->x, coord->xy2->x, xy->x);
	else
		percent = ft_percent(coord->xy1->y, coord->xy2->y, xy->y);
	r = ft_get_light(((coord->color->color_start + 350) >> 16) & 0xFF,
						(coord->color->color_end >> 16) & 0xFF, percent);
	g = ft_get_light(((coord->color->color_start + 350) >> 8) & 0xFF,
						(coord->color->color_end >> 8) & 0xFF, percent);
	b = ft_get_light(coord->color->color_start & 0xFF,
						coord->color->color_end & 0xFF, percent);
	return ((r << 16) | (g << 8) | b);
}
