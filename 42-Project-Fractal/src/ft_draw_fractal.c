/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_fractal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 10:32:50 by vokrut            #+#    #+#             */
/*   Updated: 2019/05/15 13:01:09 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

static void		ft_img_pixel_put(t_image *image, int x, int y, int color)
{
	if (x >= 0 && x < IMG_W && y >= 0 && y < IMG_H)
		*(int *)(image->data + ((x + (y * IMG_W)) * image->bpp)) = color;
}

static void		ft_to_cart(t_fract *frac)
{
	frac->h = (float)(frac->h - frac->img_height) / frac->zoom;
	frac->w = (float)(frac->w - frac->img_width) / frac->zoom;
}

static void		ft_select_fractal(t_fract *frac)
{
	if (frac->frac_type == 1)
		frac->iterasion = ft_julia(frac);
	if (frac->frac_type == 2)
		frac->iterasion = ft_mandelbrot(frac);
	if (frac->frac_type == 3)
		frac->iterasion = ft_lambda(frac);
	if (frac->frac_type == 4)
		frac->iterasion = ft_spider(frac);
	if (frac->frac_type == 5)
		frac->iterasion = ft_burningship(frac);
	if (frac->frac_type == 6)
		frac->iterasion = ft_tricorn(frac);
	if (frac->frac_type == 7)
		frac->iterasion = ft_unknown(frac);
}

void			ft_main_fractal(t_fract *frac)
{
	int		h;
	int		w;

	h = 0;
	while (h < WIN_H)
	{
		w = 0;
		while (w < WIN_W)
		{
			frac->h = h;
			frac->w = w;
			ft_to_cart(frac);
			ft_select_fractal(frac);
			frac->color = ft_create_color(frac->iterasion, 0, ITERASION);
			ft_img_pixel_put(frac->image, h, w, frac->color);
			++w;
		}
		++h;
	}
}
