/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 09:22:18 by vokrut            #+#    #+#             */
/*   Updated: 2019/03/20 18:05:03 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <stdio.h>

typedef	struct		s_list
{
	char			**tetr_arr;
	char			symbol;
	struct s_list	*next;
}					t_list;

t_list				*ft_add(t_list *list, char **arr);
int					ft_algorithm(char **map, t_list *tetr);
int					ft_list_size(t_list *list);
t_list				*ft_valid_input(int fd);
char				**ft_create_map(int size);
int					ft_map_size(int n);
void				ft_print_solution(char **map);
t_list				*ft_cleaning(t_list *tetr);
void				ft_free_list(t_list *list);
void				ft_free_map(char **map, int size);
char				**ft_create_arr(char **arr);
int					ft_check_line(char *line, char **arr);
int					ft_check1(int ret, int j, char **arr);
int					ft_check2(int ret, char *line);
int					ft_check_symbol(char *str);

#endif
