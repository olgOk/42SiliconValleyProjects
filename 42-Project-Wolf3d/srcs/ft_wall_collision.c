/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wall_collision.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 12:05:33 by vokrut            #+#    #+#             */
/*   Updated: 2019/08/26 16:17:59 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		ft_wall_collision(float x, float y, t_info *info)
{
	if (x < 0 || x > WIN_WIDTH || y < 0 || y > WIN_HEIGHT)
		return (1);
	if (info->map[(int)floorf(y)][(int)floorf(x)])
		return (1);
	return (0);
}
