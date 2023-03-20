/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 20:59:56 by vokrut            #+#    #+#             */
/*   Updated: 2019/08/31 21:05:44 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# define WIN_WIDTH 1600
# define WIN_HEIGHT 720
# define IMG_W 1280
# define IMG_H 720
# define IMG_2D_MAP_WIDTH 320
# define IMG_2D_MAP_HEIGHT 320
# define FOV_ANGLE M_PI / 3
# define SCALE_FACTOR 0.4
# define GRID_SIZE 32
# define NUMBER_OF_WALL_TEXTURES 5
# define ROTATION_SPEED 5 * (M_PI / 180.0)
# define MOVE_SPEED 1.0

# define I(theta) (theta > 0.0 && theta < (M_PI_2)) ? (1) : (0)
# define II(theta) (theta > (M_PI_2) && theta < (M_PI)) ? (1) : (0)
# define III(theta) (theta > (M_PI) && theta < (1.5 * M_PI)) ? (1) : (0)
# define IV(theta) (theta > (1.5 * M_PI) && theta < (2.0 * M_PI)) ? (1) : (0)

/*
** II  |  I
** ---------
** III |  IV
*/

# include <fcntl.h>
# include <math.h>
# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include "keys.h"

/*
** Static structures
** fov - field of view, how wide the player can see, start value = 60
** struct s_2d_map represents wall and player positions on 2D map
*/

typedef struct		s_raycasting
{
	int				tilestep_x;
	int				tilestep_y;
	double			xstep;
	double			ystep;
	double			xintercept;
	double			yintercept;
	int				x;
	int				y;
	int				y_increment;
	int				x_increment;
	float			real_angle;
	double			p1;
	double			p2;
}					t_raycasting;

typedef struct		s_ray
{
	double			x;
	double			y;
	double			length;
	int				color;
	int				pixels_in_width;
	int				index;
}					t_ray;

typedef struct		s_settings
{
	float			fov;
	int				music;
}					t_settings;

typedef struct		s_mlx
{
	void			*init;
	void			*win;
}					t_mlx;

typedef struct		s_image
{
	void			*img;
	char			*data;
	int				size;
	int				endian;
	int				bpp;
	int				width;
	int				height;
}					t_image;

typedef struct		s_2d_map
{
	int				grid_size;
	int				num_rows;
	int				num_col;
	int				img_width;
	int				img_heigh;
}					t_2d_map;

/*
** struct s_player represents information about the player
** int x -- x player coordinate in units
** int y --y player coordinate in units
** float grid_x; -- x coordinate within a unit; Range:  0 =< coord_x < 1
** float grid_y -- y coordinate within a unit; Range:   0 =< coord_y < 1
** float actual_x is x coordinate of the player in grid + x coordinate of unit
** float actual_y is y coordinate of the player in grid + y coordinate of unit
** float view_vector -- angle of view ; Range: 0 =< view_vector < 360
** float rotation_speed -- how many degrees increments/decrements
**										when turning left or right
** float move_speed -- a speed at which player moves in the maze
*/

typedef struct		s_player
{
	int				x;
	int				y;
	float			grid_x;
	float			grid_y;
	float			actual_x;
	float			actual_y;
	float			view_vector;
	float			rotation_speed;
	float			move_speed;
}					t_player;

/*
** struct s_info consists of all the information needed for maitaining the game
** int   **map represents positions of walls; 0 - empty space, 1,2,... - walls
** int   map_x -- width of the map
** int   map_y -- height of the map
** int   choice -- game menu: 1 for play, 2 for settings, 3 for exit
** int   game_stage -- 0 for menu, 1 for raycasting
** t_player   player -- player's structure
** t_mlx      mlx -- graphical windows
** t_image    *menu_image -- image for a menu
** t_image    *skybox -- image for the ceilling
** t_image    image -- game image
** t_image    image_2d -- image of the 2D map representation
** t_image    *wall_textures -- array of the textures for
**									the walls representation
** t_image    *ceiling_textures -- array of the textures for the
** 									ceilling representation
** t_image    *sprites[NUMBER_OF_SPRITES] -- array of sprites
** t_settings settings -- setting's structure
** t_2d_map   map_2d -- stores 2D map information
*/

typedef struct		s_info
{
	int				**map;
	int				map_x;
	int				map_y;
	int				choice;
	int				game_stage;
	t_player		player;
	t_mlx			mlx;
	t_image			*menu_image;
	t_image			*skybox;
	t_image			image;
	t_image			image_2d;
	t_image			*wall_textures[NUMBER_OF_WALL_TEXTURES];
	t_settings		settings;
	t_2d_map		map_2d;
}					t_info;

/*
** Dynamic Structures
*/

typedef struct		s_list
{
	char			*line;
	struct s_list	*next;
}					t_list;

/*
** Struct Operations
*/

void				delete_list(t_list **list);
t_list				*add_list_back(t_list *list, char *line);
int					size_list(t_list *list);

/*
** Movement
*/

void				ft_move_right(t_info *info);
void				ft_move_down(t_info *info);
void				ft_move_left(t_info *info);
void				ft_move_up(t_info *info);

/*
** Game Functions
*/

void				find_distances(t_raycasting *r, t_info *info);
void				actual_raycasting(t_raycasting *r, t_info *info);
void				define_components_of_ray_2(t_raycasting *r, \
								float index_theta, t_info *info);
void				define_components_of_ray_1(t_raycasting *r, \
								float index_theta, t_info *info);
t_ray				assign_ray(float p, float x, float y, int color);
void				ft_img_pixel_put(t_image *image, int x, int y, int color);
void				ft_img_pixel_put2(t_info *info, int x, int y, int color);
void				draw_map_background(t_info *info);
void				draw_grid_line_y(int x1, int y1, int y2, t_info *info);
void				draw_grid_line_x(int x1, int y1, int x2, t_info *info);
void				ft_main_call(t_info *info, int fd);
void				read_map(t_info *info, int fd);
void				raycasting(t_info *info);
void				ft_risujka(t_info *info);
void				ft_img_pixel_put(t_image *image, int x, int y, int color);
int					key_press_hook(int key, t_info *info);
int					ft_wall_collision(float x, float y, t_info *info);
float				ft_quadrant(float alpha);
void				ft_draw_map_navigation(t_info *info);
int					ft_create_color(int x, int xmin, int xmax);
void				ft_textures(t_info *info);
void				ft_menu(t_info *info);

#endif
