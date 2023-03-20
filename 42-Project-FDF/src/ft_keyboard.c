/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyboard.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 15:12:46 by vokrut            #+#    #+#             */
/*   Updated: 2019/05/02 17:03:43 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

static void	ft_zoom_in(t_coord *coord)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < coord->h)
	{
		j = 0;
		while (j < coord->w)
		{
			coord->xyz_cart[i][j]->x *= 1.3000;
			coord->xyz_cart[i][j]->y *= 1.3000;
			coord->xyz_cart[i][j]->x *= 1.1000;
			j++;
		}
		i++;
	}
}

static void	ft_zoom_out(t_coord *coord)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < coord->h)
	{
		j = 0;
		while (j < coord->w)
		{
			coord->xyz_cart[i][j]->x /= 1.3000;
			coord->xyz_cart[i][j]->y /= 1.3000;
			coord->xyz_cart[i][j]->x /= 1.1000;
			j++;
		}
		i++;
	}
}

static void	ft_modify_projection(t_coord *coord, int key)
{
	if (key == 123)
		coord->an += 0.111900;
	if (key == 124)
		coord->an -= 0.111900;
}

static void	ft_die(t_coord *coord)
{
	ft_memdel((void**)&coord->win->mlx_ptr);
	ft_memdel((void**)&coord->win->win_ptr);
	ft_memdel((void**)&coord->win);
	ft_free(coord);
	exit(1);
}

int			ft_keyboard(int key, t_coord *coord)
{
	if (key == ESC)
		ft_die(coord);
	if (key == 126)
		ft_zoom_in(coord);
	if (key == 125)
		ft_zoom_out(coord);
	if (key == 123 || key == 124)
		ft_modify_projection(coord, key);
	if (key == 126 || key == 125 || key == 123 || key == 124)
	{
		mlx_clear_window(coord->win->mlx_ptr, coord->win->win_ptr);
		ft_to_iso(coord);
		ft_draw(coord);
	}
	return (1);
}
