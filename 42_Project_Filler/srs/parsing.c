/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 12:04:38 by user              #+#    #+#             */
/*   Updated: 2020/04/15 09:02:59 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	store_map_size(t_game_info *game, char *str_to_pars)
{
	int		index;

	index = 0;
	while (!ft_isdigit(str_to_pars[index]))
		++index;
	game->map_row = ft_atoi(&str_to_pars[index]);
	while (ft_isdigit(str_to_pars[index]))
		++index;
	++index;
	game->map_col = ft_atoi(&str_to_pars[index]);
}

void store_piece_size(t_game_info *game, char *str_to_pars)
{
    int		index;

	index = 0;
	while (!ft_isdigit(str_to_pars[index]))
		++index;
	game->piece_y = ft_atoi(&str_to_pars[index]);
	while (ft_isdigit(str_to_pars[index]))
		++index;
	++index;
	game->piece_x = ft_atoi(&str_to_pars[index]);
}

void map_parsing(t_game_info *game)
{
    char    *str_to_pars;
    int     i;
    static int index;

    if (!index)
        index = 0;
    str_to_pars = NULL;
    while (1)
    {
        while (get_next_line(0, &str_to_pars) > -1)
        {
            if (!game->player_char)
                name_parsing(game, str_to_pars);
            if (!game->map_row && !game->map_col && ft_strstr(str_to_pars, "Plateau"))
            {
                store_map_size(game, str_to_pars);
                create_map(game);
            }
            if (str_to_pars[0] == ' ' || str_to_pars[0] == '\t')
                continue ;
            i = 0;
            while(ft_isdigit(str_to_pars[i]))
                ++i;
            if (!str_to_pars[i])
                continue ;
            if (str_to_pars[i] == ' ' && game->map)
            {
                ft_strcpy(game->map[index++], str_to_pars + 4);
                if (index == game->map_row)
                    index = 0;
            }
            if (ft_strstr(str_to_pars, "Piece"))
            {
                store_piece_size(game, str_to_pars);
                create_piece_map(game);
            }

            if (game->piece && (str_to_pars[0] == '*' || str_to_pars[0] == '.'))
            {
                ft_strcpy(game->piece[index++], str_to_pars);
                if (index == game->piece_y)
                {
                    index = 0;
                    // printf("8 2\n");
                    placement(game);
                    ft_clean_array(game);
                    // return ;
                    // break ;
                }
            }
            ft_strdel(&str_to_pars);
        }
        ft_strdel(&str_to_pars);
    }
}

void name_parsing(t_game_info *game, char *str_to_pars)
{
    if (ft_strstr(str_to_pars, "$$$ exec p") && ft_strstr(str_to_pars, "vokrut"))
    {
        game->player_char = 'X';
        game->enemy_char = 'O';
        if (str_to_pars[10] == '1')
        {
            game->player_char = 'O';
            game->enemy_char = 'X';
        }
    }
}

// void name_parsing(t_game_info *game)
// {
//     char    *str_to_pars;

//     str_to_pars = NULL;
//     get_next_line(0, &str_to_pars);
//     if (ft_strstr(str_to_pars, "$$$ exec p") && ft_strstr(str_to_pars, "vokrut"))
//     {
//         game->player_char = 'X';
//         game->enemy_char = 'O';
//         if (str_to_pars[10] == '1')
//         {
//             game->player_char = 'O';
//             game->enemy_char = 'X';
//         }
//     }
//     ft_strdel(&str_to_pars);
// }
