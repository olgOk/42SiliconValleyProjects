/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 22:36:40 by vokrut            #+#    #+#             */
/*   Updated: 2019/03/24 22:37:58 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : ft_list_size
Expected files   : ft_list_size.c, ft_list.h
Allowed functions:
--------------------------------------------------------------------------------
Write a function that returns the number of elements in the linked list that's
passed to it.
It must be declared as follows: int        ft_list_size(t_list *begin_list);
You must use the following structure, and turn it in as a file called
ft_list.h

#ifndef FT_LIST_H
# define FT_LIST_H

typedef struct    s_list
{
    struct s_list          *next;
    void                   *data;
}                          t_list;

#endif
*/

#include "ft_list.h"

int        ft_list_size(t_list *begin_list)
{
        t_list        *temp;
        int                count;

        count = 0;
        temp = begin_list;
        while (temp)
        {
                count++;
                temp = temp->next;
        }
        return (count);
}