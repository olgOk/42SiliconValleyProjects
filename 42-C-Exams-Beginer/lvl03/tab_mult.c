/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 19:48:37 by vokrut            #+#    #+#             */
/*   Updated: 2019/03/30 11:29:36 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Assignment name  : tab_mult
Expected files   : tab_mult.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that displays a number's multiplication table.

The parameter will always be a strictly positive number that fits in an int,
and said number times 9 will also fit in an int.

If there are no parameters, the program displays \n.

Examples:

$>./tab_mult 9
1 x 9 = 9
2 x 9 = 18
3 x 9 = 27
4 x 9 = 36
5 x 9 = 45
6 x 9 = 54
7 x 9 = 63
8 x 9 = 72
9 x 9 = 81
$>./tab_mult 19
1 x 19 = 19
2 x 19 = 38
3 x 19 = 57
4 x 19 = 76
5 x 19 = 95
6 x 19 = 114
7 x 19 = 133
8 x 19 = 152
9 x 19 = 171
$>
$>./tab_mult | cat -e
$
$>
*/

#include <unistd.h>

int        ft_atoi(const char *str)
{
    int        i;
    int        nbr;
        int        sign;

        i = 0;
        nbr = 0;
        sign = 1;
        while (str[i] == ' ' || str[i] == '\n' || str[i] == '\r' || str[i] == '\t'
                        || str[i] == '\v' || str[i] == '\f')
                i++;
        if (str[i] == '-' || str[i] == '+')
                if (str[i++] == '-')
                        sign = -1;
        while (str[i] >= '0' && str[i] <= '9')
                nbr = (nbr * 10) + (str[i++] - '0');
        return (nbr * sign);
}

void        ft_putnbr(int nbr)
{
    char        c;

    if (nbr < 0)
    {
        write(1, "-", 1);
        nbr *= -1;
    }
    else if (nbr < 10)
    {
        c = nbr + '0';
        write(1, &c, 1);
    }
    else
    {
        ft_putnbr(nbr / 10);
        ft_putnbr(nbr % 10);
    }
}

int main(int argc, char **av)
{
    int i;
    int num;

    if (argc == 2)
    {
        i = 0;
        num = ft_atoi(av[1]);
        while(++i < 10)
        {
            ft_putnbr(i);
            write(1, " x ", 3);
            ft_putnbr(num);
            write(1, " = ", 3);
            ft_putnbr(i * num);
            write(1, "\n", 1);
        }
    }
    else
        write (1, "\n", 1);
    return (0);
}