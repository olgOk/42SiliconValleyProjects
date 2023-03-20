/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 10:29:50 by vokrut            #+#    #+#             */
/*   Updated: 2019/03/06 10:34:12 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Assignment name  : alpha_mirror
Expected files   : alpha_mirror.c
Allowed functions: write
--------------------------------------------------------------------------------
Write a program called alpha_mirror that takes a string and displays this string
after replacing each alphabetical character by the opposite alphabetical
character, followed by a newline.
'a' becomes 'z', 'Z' becomes 'A'
'd' becomes 'w', 'M' becomes 'N'
and so on.
Case is not changed.
If the number of arguments is not 1, display only a newline.
Examples:
$>./alpha_mirror "abc"
zyx
$>./alpha_mirror "My horse is Amazing." | cat -e
Nb slihv rh Znzarmt.$
$>./alpha_mirror | cat -e
$
$>                                                              */

#include <unistd.h>

int                main(int argc, char **argv)
{
    int i;

    i = 0;
    while (argc == 2 && argv[1][i])
    {
        if ('A' <= argv[1][i] && 'Z' >= argv[1][i])
        {
            argv[1][i] = 'Z' + 'A' - argv[1][i];
            write(1, &argv[1][i], 1);
        }
        else if ('a' <= argv[1][i] && 'z' >= argv[1][i])
        {
            argv[1][i] = 'z' + 'a' - argv[1][i];
            write(1, &argv[1][i], 1);
        }
        else
        write(1, &argv[1][i], 1);
        i ++;
    }
    write(1, "\n", 1);
    return (0);
}