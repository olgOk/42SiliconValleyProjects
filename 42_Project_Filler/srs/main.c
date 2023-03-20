/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 11:44:43 by user              #+#    #+#             */
/*   Updated: 2020/04/14 19:08:06 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int    main()
{
    t_game_info game;

    ft_bzero(&game, sizeof(t_game_info));
    // while (!game.player_char)
    //     name_parsing(&game);
    map_parsing(&game);
    // pintf("1 1\n");
    return 0;
}