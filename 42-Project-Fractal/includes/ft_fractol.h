/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 14:17:45 by vokrut            #+#    #+#             */
/*   Updated: 2019/05/15 11:04:10 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

# include <math.h>
# include <stdio.h>
# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"

# define WIN_H 600
# define WIN_W 600
# define IMG_H 600
# define IMG_W 600
# define ITERASION 100
# define INF 4
# define ZOOM 100
# define JULIA_RE -0.70
# define JULIA_IM 0.27015
# define LAMBDA_RE 0.85
# define LAMBDA_IM 0.6

typedef struct		s_win
{
	void			*mlx_ptr;
	void			*win_ptr;
}					t_win;

typedef struct		s_compex
{
	float			x;
	float			y;
}					t_complex;

typedef struct		s_image
{
	void			*ptr;
	char			*data;
	char			*str;
	int				bpp;
	int				size_line;
	int				endian;
}					t_image;

typedef struct		s_fract
{
	float			h;
	float			w;
	int				img_width;
	int				img_height;
	int				color;
	int				frac_type;
	int				iterasion;
	int				zoom;
	float			j_re;
	float			j_im;
	t_complex		c;
	t_complex		z;
	t_win			*win;
	t_image			*image;
}					t_fract;

char				*ft_strupdate(char *str, char *update);
void				ft_main_fractal(t_fract *frac);
int					ft_mandelbrot(t_fract *frac);
int					ft_julia(t_fract *frac);
int					ft_lambda(t_fract *frac);
int					ft_spider(t_fract *frac);
int					ft_create_color(int x, int xmin, int xmax);
int					ft_burningship(t_fract *frac);
int					ft_tricorn(t_fract *frac);
int					ft_unknown(t_fract *frac);
int					ft_keyboard(int key, t_fract *frac);
int					mouse_press(int mouse, int x, int y, t_fract *frac);
int					mouse_move(int x, int y, t_fract *frac);
void				ft_die(t_fract *frac);

#endif
