/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyboard.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 21:49:58 by vokrut            #+#    #+#             */
/*   Updated: 2019/08/31 21:09:56 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			enter_on_0(t_info *info)
{
	if (info->choice == 3)
	{
		system("killall afplay");
		exit(0);
	}
	else if (info->choice == 2)
	{
		info->settings.music = (info->settings.music) ? (0) : (1);
		if (info->settings.music)
			system("afplay files/music/battle1.mp3 &");
		else
			system("killall afplay");
	}
	else
	{
		info->game_stage = 1;
		ft_risujka(info);
	}
}

void			game_stage_0(int key, t_info *info)
{
	if (key == KEY_UPARROW)
		--info->choice;
	if (key == KEY_DOWNARROW)
		++info->choice;
	if (info->choice == 0)
		info->choice = 3;
	if (info->choice == 4)
		info->choice = 1;
	if (key == KEY_RETURN)
		enter_on_0(info);
	if (key != KEY_RETURN || info->choice != 1)
		ft_menu(info);
}

void			game_stage_1(int key, t_info *info)
{
	if (key == KEY_ESCAPE)
	{
		info->game_stage = 0;
		info->choice = 1;
		ft_menu(info);
	}
	if (key == KEY_RIGHTARROW)
		ft_move_right(info);
	if (key == KEY_LEFTARROW)
		ft_move_left(info);
	if (key == KEY_UPARROW)
		ft_move_up(info);
	if (key == KEY_DOWNARROW)
		ft_move_down(info);
}

int				key_press_hook(int key, t_info *info)
{
	if (info->game_stage == 0)
		game_stage_0(key, info);
	else
		game_stage_1(key, info);
	return (1);
}
