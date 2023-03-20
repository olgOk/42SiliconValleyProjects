/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 12:06:19 by vokrut            #+#    #+#             */
/*   Updated: 2019/05/02 18:42:27 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	ft_x_line(t_coord *coord, t_point *xy1, t_point *xy2)
{
	double		dx;
	double		dy;
	double		inc_y;
	double		grad;
	t_point		*xyz;

	xyz = (t_point *)malloc(sizeof(t_point));
	inc_y = 0.0;
	dx = xy2->x - xy1->x;
	dy = xy2->y - xy1->y;
	(dy < 0.0) ? (inc_y -= 1.0) : (inc_y += 1.0);
	(dy < 0.0) ? (dy = -dy) : (inc_y += 0.0);
	grad = 2.0 * dy - dx;
	xyz->x = xy1->x - 1.0;
	xyz->y = xy1->y;
	while (++xyz->x < xy2->x)
	{
		mlx_pixel_put(coord->win->mlx_ptr, coord->win->win_ptr, xyz->x,
						xyz->y, ft_color_grad(coord, dx, dy, xyz));
		(grad > 0) ? (xyz->y += inc_y) : (grad += 0.0);
		(grad > 0) ? (grad -= 2.0 * dx) : (grad += 0.0);
		grad += 2.0 * dy;
	}
	free(xyz);
}

void	ft_y_line(t_coord *coord, t_point *xy1, t_point *xy2)
{
	double		dx;
	double		dy;
	double		inc_x;
	double		grad;
	t_point		*xyz;

	xyz = (t_point *)malloc(sizeof(t_point));
	inc_x = 0.0;
	dx = xy2->x - xy1->x;
	dy = xy2->y - xy1->y;
	(dx < 0.0) ? (inc_x -= 1) : (inc_x = 1.0);
	(dx < 0.0) ? (dx = -dx) : (inc_x += 0.0);
	grad = 2.0 * dx - dy;
	xyz->x = xy1->x;
	xyz->y = xy1->y - 1;
	while (++xyz->y < xy2->y)
	{
		mlx_pixel_put(coord->win->mlx_ptr, coord->win->win_ptr, xyz->x,
						xyz->y, ft_color_grad(coord, dx, dy, xyz));
		(grad > 0) ? (xyz->x += inc_x) : (grad += 0.0);
		(grad > 0) ? (grad -= 2.0 * dy) : (grad += 0.0);
		grad += 2.0 * dx;
	}
	free(xyz);
}

void	ft_draw_line(t_coord *coord)
{
	double		delta_x;
	double		delta_y;

	delta_x = (coord->xy1->x < coord->xy2->x) ? (coord->xy2->x - coord->xy1->x)
				: (coord->xy1->x - coord->xy2->x);
	delta_y = (coord->xy1->y < coord->xy2->y) ? (coord->xy2->y - coord->xy1->y)
				: (coord->xy1->y - coord->xy2->y);
	if (delta_y < delta_x)
	{
		if (coord->xy2->x < coord->xy1->x)
			ft_x_line(coord, coord->xy2, coord->xy1);
		else
			ft_x_line(coord, coord->xy1, coord->xy2);
	}
	else
	{
		if (coord->xy2->y < coord->xy1->y)
			ft_y_line(coord, coord->xy2, coord->xy1);
		else
			ft_y_line(coord, coord->xy1, coord->xy2);
	}
}
