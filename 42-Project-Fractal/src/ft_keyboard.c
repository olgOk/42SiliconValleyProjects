/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyboard.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 12:31:41 by vokrut            #+#    #+#             */
/*   Updated: 2019/05/15 11:31:07 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

static void	ft_move_up(t_fract *frac)
{
	frac->img_width *= 0.8;
	ft_bzero(frac->image->data, IMG_H * IMG_W * frac->image->bpp);
	ft_main_fractal(frac);
	mlx_put_image_to_window(frac->win->mlx_ptr, frac->win->win_ptr,
			frac->image->ptr, 0, 0);
}

static void	ft_move_down(t_fract *frac)
{
	frac->img_width *= 1.2;
	ft_bzero(frac->image->data, IMG_H * IMG_W * frac->image->bpp);
	ft_main_fractal(frac);
	mlx_put_image_to_window(frac->win->mlx_ptr, frac->win->win_ptr,
			frac->image->ptr, 0, 0);
}

static void	ft_move_right(t_fract *frac)
{
	frac->img_height *= 1.2;
	ft_bzero(frac->image->data, IMG_H * IMG_W * frac->image->bpp);
	ft_main_fractal(frac);
	mlx_put_image_to_window(frac->win->mlx_ptr, frac->win->win_ptr,
			frac->image->ptr, 0, 0);
}

static void	ft_move_left(t_fract *frac)
{
	frac->img_height *= 0.8;
	ft_bzero(frac->image->data, IMG_H * IMG_W * frac->image->bpp);
	ft_main_fractal(frac);
	mlx_put_image_to_window(frac->win->mlx_ptr, frac->win->win_ptr,
			frac->image->ptr, 0, 0);
}

int			ft_keyboard(int key, t_fract *frac)
{
	if (key == 53)
		ft_die(frac);
	if (key == 126)
		ft_move_up(frac);
	if (key == 125)
		ft_move_down(frac);
	if (key == 124)
		ft_move_right(frac);
	if (key == 123)
		ft_move_left(frac);
	return (1);
}
