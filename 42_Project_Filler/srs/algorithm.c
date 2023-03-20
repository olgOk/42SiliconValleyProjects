/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 10:30:01 by user              #+#    #+#             */
/*   Updated: 2020/04/15 12:09:01 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void    calculate_score(t_game_info *game, int x0, int y0)
{
    int i;
    int j;
    int score_curr;

    game->score_min = 2147483647;
    score_curr = 0;
    i = 0;
    while (i < game->piece_y)
    {
        j = 0;
        while (j < game->piece_x)
        {
            if (game->piece[i][j] == '*' && game->hit_map[y0 + i][x0 + j] > 0)
                score_curr += game->hit_map[y0 + i][x0 + j];
            ++j;
        }
        ++i;
    }
    if (score_curr < game->score_min)
    {
        game->score_min = score_curr;
        // printf("score_min = %d", game->score_min);
        game->min_x = x0;
        game->min_y = y0;
    }
}

int color_cell(t_game_info *game, int val)
{
    int i;
    int j;
    int flag;

    i = 0;
    flag = 0;
    while (i < game->map_row)
    {
        j = 0;
        while (j < game->map_col)
        {
            if (game->hit_map[i][j] == -1)
            {
                if ((i > 0 && game->hit_map[i - 1][j] == val - 1) || \
                    (j > 0 && game->hit_map[i][j - 1] == val - 1) || \
                    (j < game->map_col - 1 && game->hit_map[i][j + 1] == val - 1) || \
                    (i < game->map_row - 1 && game->hit_map[i + 1][j] == val - 1))
                {
                    flag = 1;
                    game->hit_map[i][j] = val;
                }
            }
            ++j;
        }
        ++i;
    }
    return (flag);
}