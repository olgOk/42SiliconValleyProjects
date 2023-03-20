/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 16:42:10 by user              #+#    #+#             */
/*   Updated: 2020/04/15 12:13:17 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int check_fit(t_game_info *game, int x, int y)
{
    if ((x + game->piece_x > game->map_col) ||
        (y + game->piece_y > game->map_row))
        return 0;
    return 1;
}

int intersects_correctly(t_game_info *game, int x, int y)
{
    int i;
    int j;
    int count = 0;

    i = 0;
    while (i < game->piece_x)
    {
        j = 0;
        while (j < game->piece_y)
        {
            if (game->piece[j][i] == '*')
            {
                if (game->map[y + j][x + i] == game->enemy_char || \
                    game->map[y + j][x + i] == game->enemy_char + 32)
                    return 0;
                if (game->map[y + j][x + i] == game->player_char || \
                    game->map[y + j][x + i] == game->player_char + 32)
                    ++count;
            }
            ++j;
        }
        ++i;
    }
    if (count == 1)
        return (1);
    return (0);
}

void placement(t_game_info *game)
{
    // print map and piece; for testing, remove later
    // int i = 0;
    // while (i < game->map_row)
    // {
    //     printf("Map:\n");
    //     printf("%s\n", game->map[i]);
    //     ++i;
    // }
    // i = 0;
    // while (i < game->piece_y)
    // {
    //     printf("Piece:\n");
    //     printf("%s\n", game->piece[i]);
    //     ++i;
    // }

    int y;
    int x;

    y = 0;
    create_and_fill_hit_map(game);
    while (y < game->map_row)
    { 
        x = 0;
        while (x < game->map_col)
        { 
            if (check_fit(game, x, y))
            {
                if (intersects_correctly(game, x, y))
                {
                    // printf("%d %d\n", y, x);
                    calculate_score(game, x, y);
                    // printf("min score = %d\n", game->score_min);
                    // printf("min y = %d, min x = %d\n", game->min_y, game->min_x);
                }
            }            
            ++x;
        }
        ++y;
    }
    printf("Final min score = %d\n", game->score_min);
    printf(" Final min y = %d, min x = %d\n", game->min_y, game->min_x);
}