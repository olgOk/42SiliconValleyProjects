/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_call.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:42:10 by vokrut            #+#    #+#             */
/*   Updated: 2019/08/27 11:49:17 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		update_skybox(t_info *info)
{
	int		x;
	int		y;
	int		x_real_beginning;
	int		tmp;

	x_real_beginning = (int)(info->player.view_vector * \
								info->skybox->width / (M_PI * 2));
	y = -1;
	while (++y < IMG_H / 2)
	{
		x = -1;
		while (++x < IMG_W)
		{
			tmp = x - (int)x_real_beginning;
			while (tmp >= info->skybox->width)
				tmp -= info->skybox->width;
			while (tmp < 0)
				tmp += info->skybox->width;
			ft_img_pixel_put(&info->image, x, y, \
		(*(int *)(&(info->skybox->data[(y * info->skybox->width + tmp) * 4]))));
		}
	}
}

void		draw_background(t_info *info)
{
	int		x;
	int		y;

	update_skybox(info);
	y = WIN_HEIGHT / 2;
	while (y < WIN_HEIGHT)
	{
		x = -1;
		while (++x < WIN_WIDTH)
			ft_img_pixel_put(&info->image, x, y, 10512668);
		++y;
	}
}

void		ft_menu(t_info *info)
{
	mlx_put_image_to_window(info->mlx.init, \
		info->mlx.win, info->menu_image, 0, 0);
	mlx_string_put(info->mlx.init, info->mlx.win, \
		500, 240, (info->choice == 1) ? (823497) : (16777215), "PLAY");
	mlx_string_put(info->mlx.init, info->mlx.win, \
		500, 260, (info->choice == 2) ? (823497) : (16777215), "MUSIC : ");
	mlx_string_put(info->mlx.init, info->mlx.win, \
		600, 260, (info->settings.music == 1) ? (823497) : (16777215), "ON");
	mlx_string_put(info->mlx.init, info->mlx.win, \
		650, 260, (info->settings.music == 0) ? (823497) : (16777215), "OFF");
	mlx_string_put(info->mlx.init, info->mlx.win, \
		500, 280, (info->choice == 3) ? (823497) : (16777215), "EXIT");
}

void		ft_risujka(t_info *info)
{
	mlx_put_image_to_window(info->mlx.init, \
							info->mlx.win, info->menu_image, 0, 0);
	draw_background(info);
	ft_draw_map_navigation(info);
	raycasting(info);
	mlx_put_image_to_window(info->mlx.init, \
							info->mlx.win, info->image.img, 0, 0);
	mlx_put_image_to_window(info->mlx.init, \
							info->mlx.win, info->image_2d.img, 1281, 0);
}

void		ft_main_call(t_info *info, int fd)
{
	int		grid_x;
	int		grid_y;

	read_map(info, fd);
	info->player.view_vector = 70 * (M_PI / 180);
	info->player.actual_x = 2.1;
	info->player.actual_y = 2.5;
	info->player.rotation_speed = ROTATION_SPEED;
	info->player.move_speed = MOVE_SPEED;
	info->settings.fov = FOV_ANGLE;
	info->game_stage = 0;
	info->choice = 1;
	info->settings.music = 1;
	system("afplay files/music/battle1.mp3 &");
	grid_x = (int)roundf(IMG_2D_MAP_WIDTH / info->map_x);
	grid_y = (int)floorf(IMG_2D_MAP_HEIGHT / info->map_y);
	info->map_2d.grid_size = (grid_x) > (grid_y) ? grid_y : grid_x;
	info->map_2d.img_width = info->map_2d.grid_size * info->map_x;
	info->map_2d.img_heigh = info->map_2d.grid_size * info->map_y;
	ft_menu(info);
}
