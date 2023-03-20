/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_last_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 17:58:59 by vokrut            #+#    #+#             */
/*   Updated: 2019/03/05 17:59:51 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Assignment name  : aff_last_param
Expected files   : aff_last_param.c
Allowed functions: write
----------------------------------------------------
Write a program that takes strings as arguments, and displays its last
argument followed by a newline.

If the number of arguments is less than 1, the program displays a newline.

Examples:
$> ./aff_last_param "zaz" "mange" "des" "chats" | cat -e
chats$
$> ./aff_last_param "j'aime le savon" | cat -e
j'aime le savon$
$> ./aff_last_param
$
*/

#include <unistd.h>

int main(int ar, char **av)
{
    int i;

    i = 0;
    while (ar > 1 && av[ar - 1][i])
        write(1, &av[ar - 1][i++], 1);
    write (1, "\n", 1);
    return (0);
}
