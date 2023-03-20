/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quadrant.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 14:40:21 by vokrut            #+#    #+#             */
/*   Updated: 2019/08/18 15:18:16 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

float	ft_quadrant(float alpha)
{
	if (I(alpha))
		return (alpha);
	else if (II(alpha))
		return (M_PI - alpha);
	else if (III(alpha))
		return (alpha - M_PI);
	else
		return (2.0 * M_PI - alpha);
}
