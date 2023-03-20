/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractals.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 15:31:17 by vokrut            #+#    #+#             */
/*   Updated: 2019/05/15 11:28:49 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

/* Function implements lambda fractal: z^2+const*/
int			ft_lambda(t_fract *frac)
{
	int			k;
	float		p;
	t_complex	t;

	k = 0;
	frac->c.x = LAMBDA_RE;
	frac->c.y = LAMBDA_IM;
	frac->z.y = frac->w;
	frac->z.x = frac->h;
	while (k < ITERASION)
	{
		t = frac->z;
		p = pow(t.y, 2.0) - pow(t.x, 2.0);
		frac->z.x = frac->c.x * (t.x + p) + frac->c.y * t.y * (2.0 * t.x - 1);
		frac->z.y = frac->c.x * t.y * (1 - 2.0 * t.x) + frac->c.y * (t.x + p);
		k++;
		if (pow(t.x, 2.0) + pow(t.y, 2.0) > (double)INF)
			break ;
	}
	return (k);
}

/*Function implements julia fractal: z^2+const*/
int			ft_julia(t_fract *frac)
{
	int			k;
	t_complex	t;

	k = 0;
	frac->z.y = frac->w;
	frac->z.x = frac->h;
	while (k < ITERASION)
	{
		t = frac->z;
		if (pow(t.x, 2.0) + pow(t.y, 2.0) > (double)INF)
			break ;
		frac->z.x = pow(t.x, 2.0) - pow(t.y, 2.0) + frac->j_re;
		frac->z.y = 2.0f * t.x * t.y + frac->j_im;
		++k;
	}
	return (k);
}

/* Function implements mandelbrot fractal: z^2+const */
int			ft_mandelbrot(t_fract *frac)
{
	int			k;
	t_complex	t;

	k = 0;
	frac->z.y = 0.0;
	frac->z.x = 0.0;
	while (k < ITERASION)
	{
		t = frac->z;
		frac->z.x = pow(t.x, 2.0) - pow(t.y, 2.0) + frac->h;
		frac->z.y = 2.0f * t.x * t.y + frac->w;
		k++;
		if (pow(t.x, 2.0) + pow(t.y, 2.0) > (double)INF)
			break ;
	}
	return (k);
}
