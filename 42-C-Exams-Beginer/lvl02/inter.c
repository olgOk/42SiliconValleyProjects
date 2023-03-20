/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 18:59:45 by vokrut            #+#    #+#             */
/*   Updated: 2019/03/23 19:30:59 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Assignment name  : inter
Expected files   : inter.c
Allowed functions: write
----------------------------------------------------------------------------
Write a program that takes two strings and displays, without doubles, the
characters that appear in both strings, in the order they appear in the first
one.
The display will be followed by a \n. If the number of arguments is not 2, 
the program displays \n.
Examples:
$>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
padinto$
$>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6ewg4$
$>./inter "rien" "cette phrase ne cache rien" | cat -e
rien$
$>./inter | cat -e
$
*/

#include <unistd.h>

int main(int    argc, char  **argv)
{
    int i;
    int j;
    int flag;

    if (argc == 3)
    {
        j = 0;
        while (argv[1][j])
        {
            i = -1;
            flag = 0;
            while (++i < j)
                if (argv[1][i] == argv[1][j])
                {
                    flag = 1;
                    break;
                }
            if (!flag)
            {
                i = 0;
                while (argv[2][i])
                {
                    if (argv[1][j] == argv[2][i])
                    {
                        write (1, &argv[1][j], 1);
                        break;
                    }
                    i++;
                }
            }
            j++;
        }
    }
    write(1, "\n", 1);
    return (0);
}