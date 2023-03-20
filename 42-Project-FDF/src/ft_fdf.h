/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 10:47:48 by vokrut            #+#    #+#             */
/*   Updated: 2019/05/02 18:38:47 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H

# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"
# define WIN_H 1024
# define WIN_W 1024
# define ESC 53

typedef struct		s_list
{
	struct s_list	*next;
	char			*line;
}					t_line;

typedef struct		s_win
{
	void			*mlx_ptr;
	void			*win_ptr;
}					t_win;

typedef struct		s_image
{
	void			*ptr;
	char			*data;
	char			*str;
	int				bpp;
	int				size_line;
	int				endian;
}					t_image;

typedef struct		s_iso
{
	int				x;
	int				y;
	int				z;

}					t_iso;

typedef struct		s_cart
{
	int				x;
	int				y;
	int				z;
}					t_cart;

typedef	struct		s_point
{
	double			x;
	double			y;
}					t_point;

typedef struct		s_color
{
	int				color_start;
	int				color_end;
	int				curr_color;
}					t_color;

typedef struct		s_coord
{
	int				**coord;
	unsigned int	h;
	unsigned int	w;
	double			an;
	t_color			*color;
	t_image			*image;
	t_win			*win;
	t_cart			***xyz_cart;
	t_iso			***xyz_iso;
	t_point			*xy1;
	t_point			*xy2;
}					t_coord;

t_line				*ft_read_file(int fd);
unsigned int		ft_len_line(char *srt);
unsigned int		ft_list_size(t_line *arr);
void				ft_modificate(t_line *arr, t_coord *coord);
void				ft_draw_line(t_coord *coord);
void				ft_cartesian(t_coord *coord);
void				ft_to_iso(t_coord *coord);
void				ft_draw(t_coord *coord);
void				ft_x_line(t_coord *coord, t_point *xy1, t_point *xy2);
void				ft_y_line(t_coord *coord, t_point *xy1, t_point *xy2);
int					ft_keyboard(int keycode, t_coord *coord);
int					ft_color_grad(t_coord *coord, double dx, double dy,
									t_point *xy);
void				ft_free_list(t_line *arr);
void				ft_free(t_coord *coord);
int					ft_start_color(int z, int min, int max);

#endif
