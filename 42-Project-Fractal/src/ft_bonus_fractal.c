/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus_fractal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 15:37:51 by vokrut            #+#    #+#             */
/*   Updated: 2019/05/15 11:17:53 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

int			ft_unknown(t_fract *frac)
{
	int			k;
	t_complex	t;

	k = 0;
	frac->c.x = frac->h;
	frac->c.y = frac->w;
	frac->z.y = 0.0;
	frac->z.x = 0.0;
	while (k < ITERASION)
	{
		t = frac->z;
		frac->z.x = t.x * (pow(t.x, 2.0) - 3 * pow(t.y, 2.0)) + frac->c.x;
		frac->z.y = t.y * (3 * pow(t.x, 2.0) - pow(t.y, 2.0)) + frac->c.y;
		k++;
		if (pow(t.x, 2.0) + pow(t.y, 2.0) > (double)INF)
			break ;
	}
	return (k);
}

/*Function implements tricorn fractal */
int			ft_tricorn(t_fract *frac)
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
		frac->z.y = -2.0f * (t.x * t.y) + frac->w;
		k++;
		if (pow(t.x, 2.0) + pow(t.y, 2.0) > (double)INF)
			break ;
	}
	return (k);
}

/*Function implements burningship fractal */
int			ft_burningship(t_fract *frac)
{
	int			k;
	t_complex	t;

	k = 0;
	frac->c.x = frac->h - 0.05;
	frac->c.y = frac->w - 0.05;
	frac->z.y = 0.0;
	frac->z.x = 0.0;
	while (k < ITERASION)
	{
		t = frac->z;
		frac->z.x = pow(t.x, 2.0) - pow(t.y, 2.0) + frac->c.x;
		frac->z.y = 2.0f * fabs(t.x * t.y) + frac->c.y;
		k++;
		if (pow(t.x, 2.0) + pow(t.y, 2.0) > (double)INF)
			break ;
	}
	return (k);
}

/* Function implements spider fractal */
int			ft_spider(t_fract *frac)
{
	int			k;
	t_complex	c2;
	t_complex	t;

	k = 0;
	frac->z.y = frac->w * 0.01;
	frac->z.x = frac->h * 0.01;
	frac->c.x = frac->z.x;
	frac->c.y = frac->z.y;
	while (k < ITERASION)
	{
		t = frac->z;
		c2 = frac->c;
		frac->z.x = pow(t.x, 2.0) - pow(t.y, 2.0) + frac->c.x;
		frac->z.y = 2.0 * t.x * t.y + frac->c.y;
		frac->c.x = c2.x / 2.0 + frac->z.x;
		frac->c.y = c2.y / 2.0 + frac->z.y;
		k++;
		if (pow(frac->z.x, 2.0) + pow(frac->z.y, 2.0) > (double)INF)
			break ;
	}
	return (k);
}
