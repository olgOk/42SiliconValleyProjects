/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 14:22:45 by vokrut            #+#    #+#             */
/*   Updated: 2019/05/15 13:10:08 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

/* Compares avaliable fractal to the fractal provided by user 
  If user provided unknown fractal type, the function will return zero */
static int		ft_assign_fractal(char *s)
{
	if (!ft_strcmp("julia", s))
		return (1);
	if (!ft_strcmp("mandelbrot", s))
		return (2);
	if (!ft_strcmp("lambda", s))
		return (3);
	if (!ft_strcmp("spider", s))
		return (4);
	if (!ft_strcmp("burningship", s))
		return (5);
	if (!ft_strcmp("tricorn", s))
		return (6);
	if (!ft_strcmp("unknown", s))
		return (7);
	return (0);
}

/* Initialize graphic image, set pointers to graphic image and graphic window */
t_image			*ft_init(t_win *win, char *fract_name)
{
	t_image		*image;

	win->mlx_ptr = mlx_init();
	win->win_ptr = mlx_new_window(win->mlx_ptr, WIN_H, WIN_W, fract_name);
	image = (t_image *)malloc(sizeof(t_image));
	image->ptr = mlx_new_image(win->mlx_ptr, IMG_H, IMG_W);
	image->data = mlx_get_data_addr(image->ptr, &image->bpp, &image->size_line,
			&image->endian);
	image->bpp /= 8;
	return (image);
}

/* Initialize graphic window. Set the size of the graphic window, 
	store name of the selected fractal */
static void		ft_main(int fr_type, char *fract_name)
{
	t_win		*win;
	t_fract		*frac;

	frac = (t_fract *)malloc(sizeof(t_fract));
	win = (t_win *)malloc(sizeof(t_win));
	frac->image = ft_init(win, fract_name);
	frac->win = win;
	frac->frac_type = fr_type;
	frac->img_height = IMG_H / 2;
	frac->img_width = IMG_W / 2;
	frac->zoom = ZOOM;
	frac->j_re = JULIA_RE;
	frac->j_im = JULIA_IM;
	ft_main_fractal(frac);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, frac->image->ptr, 0, 0);
	mlx_key_hook(win->win_ptr, ft_keyboard, frac);
	mlx_hook(win->win_ptr, 6, 0, mouse_move, frac);
	mlx_hook(win->win_ptr, 4, 0, mouse_press, frac);
	mlx_loop(win->mlx_ptr);
}

int				main(int argc, char **av)
{
	int			i;
	int			fractal;
	char		*frac_name;

	if (argc < 2) /*Assures user provided fractal name, if not exit the program */
	{
		ft_putstr("Usage ./fractol [julia, mandelbrot, lambda, spider, ");
		ft_putstr("burningship, tricorn, unknown]");
		exit(-1);
	}
	i = 0;
	/*Assures user provided one of the avaliable fractal name, if not xit the program*/
	while (++i < argc)
	{
		if (!(fractal = ft_assign_fractal(av[i])))
		{
			ft_putstr("Available fractals -- julia, mandelbrot, lambda, ");
			ft_putstr("spider, burningship, tricorn, unknown]");
			exit(-1);
		}
		frac_name = ft_strdup(av[1]);
		frac_name = ft_strupdate(frac_name, ft_strjoin("Fractal ", frac_name));
		ft_main(fractal, frac_name);
	}
	return (0);
}
