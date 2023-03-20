/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_die.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 10:27:11 by vokrut            #+#    #+#             */
/*   Updated: 2019/05/15 11:20:38 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

/*Free memory and exit the program */
void	ft_die(t_fract *frac)
{
	ft_memdel((void**)&frac->win->mlx_ptr);
	ft_memdel((void**)&frac->win->win_ptr);
	ft_memdel((void**)&frac->win);
	ft_memdel((void**)&frac->image);
	ft_memdel((void**)&frac);
	exit(1);
}
