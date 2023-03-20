/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 17:37:18 by vokrut            #+#    #+#             */
/*   Updated: 2019/08/27 11:54:32 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** Delete image of the texture in a case it does not exists or memory
** allocation fails
*/

t_image			*del_texture(t_mlx win, t_image *texture)
{
	if (texture)
	{
		if (texture->img)
			mlx_destroy_image(win.init, texture->img);
		ft_memdel((void **)&texture);
	}
	return (NULL);
}

/*
** Initialization of the wall images
*/

t_image			*initialize_texture(t_mlx win, char *img_path)
{
	t_image		*texture;

	texture = (t_image *)malloc(sizeof(t_image));
	if (!(texture->img = mlx_xpm_file_to_image(win.init, img_path, \
						&texture->width, &texture->height)))
		return (del_texture(win, texture));
	texture->data = mlx_get_data_addr(texture->img, &texture->bpp, \
						&texture->size, &texture->endian);
	texture->bpp /= 8;
	return (texture);
}

/*
** loading the textures for the walls
*/

void			ft_textures(t_info *info)
{
	int			i;
	static char	*wall_path[NUMBER_OF_WALL_TEXTURES + 1] = { \
								"./textures/wall/qbox.xpm", \
								"./textures/wall/redbrick.xpm", \
								"./textures/wall/wood.xpm", \
								"./textures/wall/stone.xpm", \
								"./textures/wall/purplestone.xpm", \
								NULL};

	info->menu_image = \
			initialize_texture(info->mlx, "./textures/menu/menu1.xpm");
	info->skybox = \
			initialize_texture(info->mlx, "./textures/ceilings/hellskybox.xpm");
	mlx_put_image_to_window(info->mlx.init, info->mlx.win, info->skybox, 0, 0);
	i = -1;
	while (++i < NUMBER_OF_WALL_TEXTURES)
		info->wall_textures[i] = initialize_texture(info->mlx, wall_path[i]);
}
