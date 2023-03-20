/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 19:46:37 by knaumov           #+#    #+#             */
/*   Updated: 2019/08/27 19:49:07 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** Players rotation left
*/

void		ft_move_left(t_info *info)
{
	info->player.view_vector += 1 * info->player.rotation_speed;
	if (info->player.view_vector >= 2.0 * M_PI)
		info->player.view_vector -= 2.0 * M_PI;
	ft_bzero(info->image.data, WIN_HEIGHT * WIN_WIDTH * info->image.bpp);
	ft_risujka(info);
}

/*
** Players rotation right
*/

void		ft_move_right(t_info *info)
{
	info->player.view_vector -= 1 * info->player.rotation_speed;
	if (info->player.view_vector < 0.0)
		info->player.view_vector += 2.0 * M_PI;
	ft_bzero(info->image.data, WIN_HEIGHT * WIN_WIDTH * info->image.bpp);
	ft_risujka(info);
}

/*
** Players movement ahead
*/

void		ft_move_up(t_info *info)
{
	float		move_step;
	float		new_player_x;
	float		new_player_y;
	float		alpha;

	move_step = 0.25 * info->player.move_speed;
	alpha = ft_quadrant(info->player.view_vector);
	if (II(info->player.view_vector) || III(info->player.view_vector))
		new_player_x = info->player.actual_x - move_step * cos(alpha);
	else
		new_player_x = info->player.actual_x + move_step * cos(alpha);
	if (I(info->player.view_vector) || II(info->player.view_vector))
		new_player_y = info->player.actual_y - move_step * sin(alpha);
	else
		new_player_y = info->player.actual_y + move_step * sin(alpha);
	if (!ft_wall_collision(new_player_x, new_player_y, info))
	{
		info->player.actual_x = new_player_x;
		info->player.actual_y = new_player_y;
		ft_bzero(info->image.data, WIN_HEIGHT * WIN_WIDTH * info->image.bpp);
		ft_risujka(info);
	}
}

/*
** Players movement back
*/

void		ft_move_down(t_info *info)
{
	float		move_step;
	float		new_player_x;
	float		new_player_y;
	float		alpha;

	move_step = -0.25 * info->player.move_speed;
	alpha = ft_quadrant(info->player.view_vector);
	if (II(info->player.view_vector) || III(info->player.view_vector))
		new_player_x = info->player.actual_x - move_step * cos(alpha);
	else
		new_player_x = info->player.actual_x + move_step * cos(alpha);
	if (I(info->player.view_vector) || II(info->player.view_vector))
		new_player_y = info->player.actual_y - move_step * sin(alpha);
	else
		new_player_y = info->player.actual_y + move_step * sin(alpha);
	if (!ft_wall_collision(new_player_x, new_player_y, info))
	{
		info->player.actual_x = new_player_x;
		info->player.actual_y = new_player_y;
		ft_bzero(info->image.data, WIN_HEIGHT * WIN_WIDTH * info->image.bpp);
		ft_risujka(info);
	}
}
