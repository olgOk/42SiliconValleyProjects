/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_grid_and_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 19:38:50 by knaumov           #+#    #+#             */
/*   Updated: 2019/08/27 19:38:51 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		draw_grid_line_x(int x1, int y1, int x2, t_info *info)
{
	while (x1 < x2)
		ft_img_pixel_put2(info, x1++, y1, 25600);
}

void		draw_grid_line_y(int x1, int y1, int y2, t_info *info)
{
	while (y1 < y2)
		ft_img_pixel_put2(info, x1, y1++, 25600);
}

void		draw_map_background(t_info *info)
{
	int		x;
	int		y;

	y = -1;
	while (++y < info->map_2d.img_heigh)
	{
		x = -1;
		while (++x < info->map_2d.img_width)
			ft_img_pixel_put2(info, x, y, 16777215);
	}
}

void		ft_img_pixel_put2(t_info *info, int x, int y, int color)
{
	if (x >= 0 && x < info->map_2d.img_width && \
		y >= 0 && y < info->map_2d.img_heigh)
		*(int *)(info->image_2d.data + ((x + (y * IMG_2D_MAP_WIDTH)) \
									* info->image_2d.bpp)) = color;
}

void		ft_img_pixel_put(t_image *image, int x, int y, int color)
{
	if (x >= 0 && x < IMG_W && y >= 0 && y < IMG_H)
		*(int *)(image->data + ((x + (y * IMG_W)) * image->bpp)) = color;
}
