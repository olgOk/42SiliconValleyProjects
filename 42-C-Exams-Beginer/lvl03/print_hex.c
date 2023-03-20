/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 17:47:01 by vokrut            #+#    #+#             */
/*   Updated: 2019/03/29 19:45:56 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Assignment name  : print_hex
Expected files   : print_hex.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a positive (or zero) number expressed in base 10,
and displays it in base 16 (lowercase letters) followed by a newline.

If the number of parameters is not 1, the program displays a newline.

Examples:

$> ./print_hex "10" | cat -e
a$
$> ./print_hex "255" | cat -e
ff$
$> ./print_hex "5156454" | cat -e
4eae66$
$> ./print_hex | cat -e
$
*/

#include <unistd.h>

void        print_hex(int p)
{
    char *str;
    int tmp[127];
    int i;


    str = "0123456789abcdef";
    if (p == 0)
        write (1, "0", 1);
    i = 0;
    while (p)
    {
        tmp[i] = str[p % 16];
        i++;
        p /= 16;
    }
    while (i >= 0)
        write(1, &tmp[i--], 1);
}

int                ft_atoi(char *str)
{
    int                i;
    int                nbr;
    int                sign;

    i = 0;
    nbr = 0;
    sign = 1;
    if (!str[i])
        return (0);
    while (str[i] == '\t' || str[i] == '\v' || str[i] == '\n' || \
            str[i] == ' ' || str[i] == '\r' || str[i] == '\f')
        ++i;
    if ((str[i] == '-' || str[i] == '+') && str[i++] == '-')
        sign *= -1;
    while (str[i] && (str[i] >= '0' && '9' >= str[i]))
        nbr = (nbr * 10) + str[i++] - '0';
    return (nbr * sign);
}

int                main(int argc, char *argv[])
{
        if (argc == 2)
                print_hex(ft_atoi(argv[1]));
        write(1, "\n", 1);
        return (0);
}
