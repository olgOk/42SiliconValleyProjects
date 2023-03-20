/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 12:56:31 by vokrut            #+#    #+#             */
/*   Updated: 2019/05/15 11:36:01 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

static void		ft_zoom_in(int x, int y, t_fract *frac)
{
	frac->img_height = x;
	frac->img_width = y;
	frac->zoom = frac->zoom * 1.2;
	ft_bzero(frac->image->data, IMG_H * IMG_W * frac->image->bpp);
	ft_main_fractal(frac);
	mlx_put_image_to_window(frac->win->mlx_ptr, frac->win->win_ptr,
			frac->image->ptr, 0, 0);
}

static void		ft_zoom_out(int x, int y, t_fract *frac)
{
	frac->img_height = x;
	frac->img_width = y;
	frac->zoom = frac->zoom * 0.8;
	ft_bzero(frac->image->data, IMG_H * IMG_W * frac->image->bpp);
	ft_main_fractal(frac);
	mlx_put_image_to_window(frac->win->mlx_ptr, frac->win->win_ptr,
			frac->image->ptr, 0, 0);
}

int				mouse_move(int x, int y, t_fract *frac)
{
	if (frac->frac_type == 1)
	{
		if (x > 0 && x < IMG_H && y > 0 && y < IMG_W)
		{
			frac->j_re = ((float)(x - frac->img_height / 2) /
					(float)(-frac->img_height / 2 - frac->img_height / 2)) *
					(-2.0f) + 1.0f;
			frac->j_im = ((float)(y - frac->img_width / 2) /
					(float)(-frac->img_width / 2 - frac->img_width / 2)) *
					(-2.0f) + 1.0f;
			ft_bzero(frac->image->data, IMG_H * IMG_W * frac->image->bpp);
			ft_main_fractal(frac);
			mlx_put_image_to_window(frac->win->mlx_ptr, frac->win->win_ptr,
					frac->image->ptr, 0, 0);
		}
	}
	return (1);
}

int				mouse_press(int mouse, int x, int y, t_fract *frac)
{
	if (mouse == 4)
		ft_zoom_in(x, y, frac);
	if (mouse == 5)
		ft_zoom_out(x, y, frac);
	return (1);
}
