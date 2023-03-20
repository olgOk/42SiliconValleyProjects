/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 22:26:28 by vokrut            #+#    #+#             */
/*   Updated: 2019/03/30 12:34:02 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : add_prime_sum
Expected files   : add_prime_sum.c
Allowed functions: write, exit
--------------------------------------------------------------------------------
Write a program that takes a positive integer as argument and displays the sum
of all prime numbers inferior or equal to it followed by a newline.

If the number of arguments is not 1, or the argument is not a positive number,
just display 0 followed by a newline.

Yes, the examples are right.

Examples:

$>./add_prime_sum 5
10
$>./add_prime_sum 7 | cat -e
17$
$>./add_prime_sum | cat -e
0$
$>
*/

#include <unistd.h>

void    ft_putchar(char c)
{
    write (1, &c, 1);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	nbr;
	int	sign;

	i = 0;
	nbr = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\r' || str[i] == '\t'
			|| str[i] == '\v' || str[i] == '\f')
		i++;
	if ((str[i] == '-' || str[i] == '+') && str[i++] == '-')
		sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
		nbr = (nbr * 10) + (str[i++] - '0');
	return (nbr * sign);
}

void    ft_putnbr(int nb)
{
    int                i;
    unsigned int    nb1;
    char            temp[10];
    
    nb1 = nb;
    if (nb < 0)
    {
        ft_putchar('-');
        nb1 = -1 * nb1;
    }
    else if (nb == 0)
        ft_putchar('0');
    else
        nb1 = nb;
    i = 0;
    while (nb1 != 0)
    {
        temp[i] = '0' + nb1 % 10;
        nb1 = nb1 / 10;
        i++;
    }
    while (i-- != 0)
    {
        ft_putchar(temp[i]);
    }
}

int ft_is_prime(int num)
{
    int i;
    
    i = 2;
    if (num < 2)
        return (0);
    while (i <= (num/2))
    {
        if (num % i == 0)
            return(0);
        i++;
    }
    return (1);
}

int                main(int argc, char **argv)
{
    int                num;
    int                sum;
    int                i;
    
    sum = 0;
    if (argc == 2)
    {
        num = ft_atoi(argv[1]);
        while (1 < num)
        {
            if (ft_is_prime(num))
                sum += num;
            num--;
        }
    }
    ft_putnbr(sum);
    write(1, "\n", 1);
    return (0);
}
