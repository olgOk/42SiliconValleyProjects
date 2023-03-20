/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map_navigation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 15:47:50 by vokrut            #+#    #+#             */
/*   Updated: 2019/08/23 18:46:47 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_draw_player_position(t_info *info)
{
	int		start_x;
	int		start_y;
	int		end_x;
	int		end_y;

	start_x = (int)floorf(info->player.actual_x) * info->map_2d.grid_size + 1;
	start_y = (int)floorf(info->player.actual_y) * info->map_2d.grid_size + 1;
	end_x = start_x + info->map_2d.grid_size - 1;
	end_y = start_y + info->map_2d.grid_size - 1;
	while (start_y < end_y)
	{
		start_x = \
			(int)floorf(info->player.actual_x) * info->map_2d.grid_size + 1;
		while (start_x < end_x)
			ft_img_pixel_put2(info, start_x++, start_y, 13369344);
		++start_y;
	}
}

void		ft_fill(t_info *info, int x, int y)
{
	int		start_x;
	int		start_y;
	int		end_x;
	int		end_y;

	start_x = x * info->map_2d.grid_size + 1;
	start_y = y * info->map_2d.grid_size + 1;
	end_x = start_x + info->map_2d.grid_size - 1;
	end_y = start_y + info->map_2d.grid_size - 1;
	while (start_y < end_y)
	{
		start_x = x * info->map_2d.grid_size + 1;
		while (start_x < end_x)
			ft_img_pixel_put2(info, start_x++, start_y, 2263842);
		++start_y;
	}
}

void		ft_draw_map_navigation(t_info *info)
{
	int		i;
	int		j;

	draw_map_background(info);
	i = -1;
	while (++i < info->map_y)
	{
		j = -1;
		while (++j < info->map_x)
		{
			draw_grid_line_x(j * info->map_2d.grid_size, \
				i * info->map_2d.grid_size, \
				(j + 1) * info->map_2d.grid_size, info);
			draw_grid_line_y(j * info->map_2d.grid_size, \
				i * info->map_2d.grid_size, \
				(i + 1) * info->map_2d.grid_size, info);
			if (info->map[i][j])
				ft_fill(info, j, i);
		}
	}
	ft_draw_player_position(info);
}
