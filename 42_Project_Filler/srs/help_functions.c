/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 13:17:11 by user              #+#    #+#             */
/*   Updated: 2020/04/15 11:14:51 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	fill_hit_map(t_game_info *game)
{
	int i;
	int j;

	i = 0;
	while (i < game->map_row)
	{
		j = 0;
		while (j < game->map_col)
		{
			game->hit_map[i][j] = -1;
			if (game->map[i][j] == game->enemy_char || game->map[i][j] == game->enemy_char+ 32)
				game->hit_map[i][j] = 0;
			if (game->map[i][j] == game->player_char || game->map[i][j] == game->player_char+32)
				game->hit_map[i][j] = -2;
			++j;
		}
		++i;
	}
	i = 1;
	while(color_cell(game, i))
		++i;
	// test hit map
	for (i=0; i < game->map_row; ++i)
	{
		for (j=0; j < game->map_col; ++j)
			printf("%3d", game->hit_map[i][j]);
		printf("\n");
	}
}

void	create_and_fill_hit_map(t_game_info *game)
{
	int i;

	i = 0;
	game->hit_map = (int **)malloc(sizeof(int *) * (game->map_row + 1));
	while (i < game->map_row)
		game->hit_map[i++] = (int *)malloc(sizeof(int) * (game->map_col + 1));
	game->hit_map[i] = NULL;
	fill_hit_map(game);
}

void    create_map(t_game_info *game)
{
	int		i;

    i = 0;
	game->map = (char **)malloc(sizeof(char *) * (game->map_row + 1));
	while (i < game->map_row)
		game->map[i++] = (char *)malloc(sizeof(char) * (game->map_col + 1));
	game->map[i] = NULL;
}

void    create_piece_map(t_game_info *game)
{
    int		i;

    i = 0;
	game->piece = (char **)malloc(sizeof(char *) * (game->piece_y + 1));
	while (i < game->piece_y)
		game->piece[i++] = (char *)malloc(sizeof(char) * (game->piece_x + 1));
	game->piece[i] = NULL;
}

void    ft_clean_array(t_game_info *game)
{
    int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(game->piece[i]))
		return ;
	while (game->piece[i])
		i++;
	while (j < i)
	{
		free(game->piece[j]);
		j++;
	}
	free(game->piece);
}