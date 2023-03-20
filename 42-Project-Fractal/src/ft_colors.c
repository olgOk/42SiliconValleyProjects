/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 09:26:51 by vokrut            #+#    #+#             */
/*   Updated: 2019/05/15 11:19:44 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

/* Color is an exponential combination of red, green, and blue components */
static float		ft_fj(float t, int j)
{
	float	farg;
	float	fvalue;

	farg = log(2.0) / 3.0 * (1.0 - 16.0 * (pow(t - 0.5 * (j - 1), 2.0)));
	fvalue = exp(farg);
	if (fvalue > 1.0)
		fvalue = 1.0;
	return (fvalue);
}

int					ft_create_color(int x, int xmin, int xmax)
{
	int		rgb[3];
	int		j;
	float	t;
	float	m;
	float	h;

	m = (xmax + xmin) / 2.0;
	h = (xmax - xmin) / 2.0;
	t = (x - m) / h;
	j = 0;
	while (j <= 2)
	{
		rgb[j] = (int)(255 * ft_fj(t, j));
		j++;
	}
	return (rgb[0] | (rgb[1] << 8) | rgb[2] << 16);
}
