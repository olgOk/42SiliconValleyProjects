/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_a.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 17:23:42 by vokrut            #+#    #+#             */
/*   Updated: 2019/03/05 17:44:35 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Assignment name  : aff_a
Expected files   : aff_a.c
Allowed functions: write
----------------------------------------------
Write a program that takes a string, and displays the first 'a' character it encounters in it, followed by a newline. If there are no 'a' characters in the string, the program just writes a newline. If the number of parameters is not 1, the program displays 'a' followed by a newline.
Example:
$> ./aff_a "abc" | cat -e
a$
$> ./aff_a "dubO a POIL" | cat -e
a$
$> ./aff_a "zz sent le poney" | cat -e
$
$> ./aff_a | cat -e
a$
*/

#include <unistd.h>

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        while (*argv[1])
        {
            if (*argv[1] == 'a')
            {
                write(1, "a", 1);
                break;
            }
            (argv[1])++;
        }
        write(1, "\n", 1);
    }
    else
        write(1, "a\n", 2);
    return (0);
}
