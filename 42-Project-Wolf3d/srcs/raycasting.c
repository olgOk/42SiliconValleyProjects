/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 22:30:31 by knaumov           #+#    #+#             */
/*   Updated: 2019/08/31 21:05:41 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void					draw_ray(t_info *info, t_ray ray)
{
	int					i;
	int					wall_height;
	int					indent;
	int					y_on_texture;
	int					x_on_texture;

	i = 0;
	wall_height = (int)(WIN_HEIGHT / ray.length);
	indent = (WIN_HEIGHT - wall_height) / 2;
	x_on_texture = ray.pixels_in_width;
	while (i < wall_height)
	{
		y_on_texture = (int)(info->wall_textures[ray.color]->height * \
						i / wall_height);
		ft_img_pixel_put(&info->image, ray.index, i + indent, \
			(*(int *)(&(info->wall_textures[ray.color]->data[(y_on_texture * \
			info->wall_textures[ray.color]->width + x_on_texture) * 4]))));
		++i;
	}
}

t_ray					define_ray(t_raycasting *r, t_info *info)
{
	t_ray				ray;

	if ((r->p1 < r->p2 || r->p2 == -1.0) && \
											r->p1 != -1.0)
	{
		ray = assign_ray(r->p1, r->x, r->yintercept, \
			info->map[(int)r->yintercept][r->x]);
		ray.pixels_in_width = (int)(info->wall_textures[ray.color]->width * \
			(ray.y - (int)ray.y));
	}
	else if (r->p2 != -1.0)
	{
		ray = assign_ray(r->p2, r->xintercept, \
			r->y, info->map[r->y][(int)r->xintercept]);
		ray.pixels_in_width = (int)(info->wall_textures[ray.color]->width * \
			(ray.x - (int)ray.x));
	}
	else
		exit(0);
	return (ray);
}

void					add_ray_to_image(t_info *info, float index_theta, \
										int ray_index)
{
	t_raycasting		r;
	t_ray				ray;

	r.real_angle = ft_quadrant(index_theta);
	r.tilestep_x = (I(index_theta) || IV(index_theta)) ? 1 : -1;
	r.tilestep_y = (I(index_theta) || II(index_theta)) ? -1 : 1;
	r.x = info->player.x;
	r.y = info->player.y;
	define_components_of_ray_1(&r, index_theta, info);
	define_components_of_ray_2(&r, index_theta, info);
	actual_raycasting(&r, info);
	find_distances(&r, info);
	ray = define_ray(&r, info);
	ray.index = abs(WIN_WIDTH - ray_index);
	draw_ray(info, ray);
}

void					raycasting(t_info *info)
{
	int		ray_index;
	float	delta_theta;
	float	index_theta;

	ray_index = 0;
	index_theta = info->player.view_vector - info->settings.fov / 2;
	delta_theta = (float)info->settings.fov / WIN_WIDTH;
	info->player.x = (int)info->player.actual_x;
	info->player.y = (int)info->player.actual_y;
	info->player.grid_x = info->player.actual_x - info->player.x;
	info->player.grid_y = info->player.actual_y - info->player.y;
	while (ray_index < WIN_WIDTH)
	{
		if (index_theta >= 2.0 * M_PI)
			index_theta -= 2.0 * M_PI;
		if (index_theta < 0.0)
			index_theta += 2.0 * M_PI;
		if (index_theta != 0 && index_theta != M_PI_2 && \
			index_theta != M_PI && index_theta != 3.0 * M_PI_2)
			add_ray_to_image(info, index_theta, ray_index);
		index_theta += delta_theta;
		++ray_index;
	}
}
