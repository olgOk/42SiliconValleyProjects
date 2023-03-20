/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:33:29 by vokrut            #+#    #+#             */
/*   Updated: 2019/09/05 23:19:56 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_image		initialize_image(t_mlx win, int width, int height)
{
	t_image	image;

	image.img = mlx_new_image(win.init, width, height);
	image.data = mlx_get_data_addr(image.img, &image.bpp, &image.size,
			&image.endian);
	image.bpp /= 8;
	return (image);
}

void		initialize(int fd)
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	info->mlx.init = mlx_init();
	info->mlx.win = mlx_new_window(info->mlx.init, \
									WIN_WIDTH, WIN_HEIGHT, "Wolf3D");
	info->image = initialize_image(info->mlx, IMG_W, IMG_H);
	info->image_2d = initialize_image(info->mlx, IMG_2D_MAP_WIDTH, IMG_H);
	ft_textures(info);
	ft_main_call(info, fd);
	mlx_hook(info->mlx.win, 2, 0, key_press_hook, info);
	mlx_loop(info->mlx.init);
}

int			main(int argc, char **av)
{
	int		fd;

	if (argc != 2)
	{
		ft_printf("Usage: ./wolf3d [map]\n");
		exit(0);
	}
	fd = open(av[1], O_RDWR);
	if (fd <= 0)
		error("Wrong map file!");
	initialize(fd);
	return (0);
}
