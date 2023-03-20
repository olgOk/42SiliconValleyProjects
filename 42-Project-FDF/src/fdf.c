/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 11:30:20 by vokrut            #+#    #+#             */
/*   Updated: 2019/05/02 15:37:19 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void		ft_initialize(t_coord *coord, t_line *arr)
{
	coord->coord = (int **)malloc(sizeof(int *) * (ft_list_size(arr) + 1));
	coord->h = ft_list_size(arr);
	coord->w = ft_len_line(arr->line);
	coord->coord[coord->h] = NULL;
	coord->xy1 = (t_point *)malloc(sizeof(t_point));
	coord->xy2 = (t_point *)malloc(sizeof(t_point));
	coord->an = 0.523599;
	coord->color = (t_color *)malloc(sizeof(t_color));
	coord->color->color_start = 16711680;
	coord->color->color_end = 16776960;
	coord->color->curr_color = 16711681;
}

t_image		*ft_win_init(t_win *win)
{
	t_image		*image;

	win->mlx_ptr = mlx_init();
	win->win_ptr = mlx_new_window(win->mlx_ptr, WIN_H, WIN_W, "Graphic FDF");
	image = (t_image*)malloc(sizeof(t_image));
	image->ptr = mlx_new_image(win->mlx_ptr, WIN_H, WIN_W);
	image->data = mlx_get_data_addr(image->ptr, &image->bpp,
									&image->size_line, &image->endian);
	image->bpp /= 8;
	return (image);
}

void		ft_main(int fd)
{
	t_coord		coord;
	t_line		*arr;
	t_win		*win;

	if (!(win = malloc(sizeof(t_win))))
		return ;
	arr = ft_read_file(fd);
	ft_initialize(&coord, arr);
	ft_modificate(arr, &coord);
	ft_cartesian(&coord);
	ft_to_iso(&coord);
	coord.image = ft_win_init(win);
	coord.win = win;
	ft_draw(&coord);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, coord.image, 0, 0);
	mlx_key_hook(win->win_ptr, ft_keyboard, &coord);
	mlx_loop(win->mlx_ptr);
}

int			main(int ag, char **av)
{
	int		fd;

	if (ag == 2)
	{
		fd = open(av[1], O_RDONLY);
		ft_main(fd);
		close(fd);
	}
	else
	{
		ft_putstr("Usage: ./fdf [name_of_file]\n");
		exit(-1);
	}
	return (0);
}
