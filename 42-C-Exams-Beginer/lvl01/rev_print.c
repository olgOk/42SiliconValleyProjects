/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 19:15:43 by vokrut            #+#    #+#             */
/*   Updated: 2019/03/05 19:16:10 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Assignment name  : rev_print
Expected files   : rev_print.c
Allowed functions: write
----------------------------------------------------
Write a program that takes a string, and displays the string in reverse
followed by a newline.
If the number of parameters is not 1, the program displays a newline.
Examples:

$> ./rev_print "zaz" | cat -e
zaz$
$> ./rev_print "dub0 a POIL" | cat -e
LIOP a 0bud$
$> ./rev_print | cat -e
$                                                                       */

#include <unistd.h>

int        ft_strlen(char *s)
{
        int i;

        i = 0;
        while (s[i])
                i++;
        return (i);
}

int        main(int ac, char **av)
{
        int a;

        if (ac == 2)
        {
            a = ft_strlen(av[1]);
            while (a--)
                write(1, &av[1][a], 1);
        }
        write(1, "\n", 1);
}
