/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_extra_functions.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 22:38:36 by knaumov           #+#    #+#             */
/*   Updated: 2019/08/31 21:05:39 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_ray					assign_ray(float p, float x, float y, int color)
{
	t_ray				ray;

	ray.length = p;
	ray.x = x;
	ray.y = y;
	ray.color = color;
	if (ray.color >= NUMBER_OF_WALL_TEXTURES)
		ray.color = 0;
	return (ray);
}

void					define_components_of_ray_1(t_raycasting *r, \
									float index_theta, t_info *info)
{
	if (I(index_theta))
		r->yintercept = info->player.actual_y - \
				(1 - info->player.grid_x) * tan(r->real_angle);
	else if (II(index_theta))
		r->yintercept = info->player.actual_y - \
				info->player.grid_x * tan(r->real_angle);
	else if (III(index_theta))
		r->yintercept = info->player.actual_y + \
				info->player.grid_x * tan(r->real_angle);
	else
		r->yintercept = info->player.actual_y + \
				(1 - info->player.grid_x) * tan(r->real_angle);
	if (I(index_theta))
		r->xintercept = info->player.actual_x + \
				info->player.grid_y / tan(r->real_angle);
	else if (II(index_theta))
		r->xintercept = info->player.actual_x - \
				info->player.grid_y / tan(r->real_angle);
	else if (III(index_theta))
		r->xintercept = info->player.actual_x - \
				(1 - info->player.grid_y) / tan(r->real_angle);
	else
		r->xintercept = info->player.actual_x + \
				(1 - info->player.grid_y) / tan(r->real_angle);
}

void					define_components_of_ray_2(t_raycasting *r, \
									float index_theta, t_info *info)
{
	if (I(index_theta) || II(index_theta))
		r->ystep = -tan(r->real_angle);
	else
		r->ystep = tan(r->real_angle);
	if (II(index_theta) || III(index_theta))
		r->xstep = -1 / tan(r->real_angle);
	else
		r->xstep = 1 / tan(r->real_angle);
	if (II(index_theta) || III(index_theta))
		r->x = info->player.x - 1;
	else
		r->x = info->player.x + 1;
	if (I(index_theta) || II(index_theta))
		r->y = info->player.y - 1;
	else
		r->y = info->player.y + 1;
	if (II(index_theta) || III(index_theta))
		r->x_increment = 1;
	else
		r->x_increment = 0;
	if (I(index_theta) || II(index_theta))
		r->y_increment = 1;
	else
		r->y_increment = 0;
}

void					actual_raycasting(t_raycasting *r, t_info *info)
{
	while (r->x < (float)info->map_x && r->yintercept < (float)info->map_y && \
		r->x >= 0 && r->yintercept >= 0 && !info->map[(int)r->yintercept][r->x])
	{
		r->x += r->tilestep_x;
		r->yintercept += r->ystep;
	}
	while (r->xintercept < (float)info->map_x && r->y < (float)info->map_y && \
		r->y >= 0 && r->xintercept >= 0 && !info->map[r->y][(int)r->xintercept])
	{
		r->y += r->tilestep_y;
		r->xintercept += r->xstep;
	}
}

void					find_distances(t_raycasting *r, t_info *info)
{
	r->p1 = -1.0;
	r->p2 = -1.0;
	if (r->x < (float)info->map_x && r->yintercept < (float)info->map_y && \
		r->x >= 0 && r->yintercept >= 0)
		r->p1 = ((r->x + r->x_increment) - info->player.x - \
			info->player.grid_x) * cos(info->player.view_vector) + \
			(info->player.y + info->player.grid_y - r->yintercept) * \
			sin(info->player.view_vector);
	if (r->xintercept < (float)info->map_x && \
		r->y < (float)info->map_y && r->y >= 0 && r->xintercept >= 0)
		r->p2 = (r->xintercept - info->player.x - info->player.grid_x) * \
			cos(info->player.view_vector) + (info->player.y + \
			info->player.grid_y - (r->y + r->y_increment)) * \
			sin(info->player.view_vector);
}
