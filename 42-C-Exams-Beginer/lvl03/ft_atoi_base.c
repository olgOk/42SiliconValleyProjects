/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 15:22:15 by vokrut            #+#    #+#             */
/*   Updated: 2019/03/30 12:21:07 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Assignment name  : ft_atoi_base
Expected files   : ft_atoi_base.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str (base N <= 16)
to an integer (base 10) and returns it.

The characters recognized in the input are: 0123456789abcdef
Those are, of course, to be trimmed according to the requested base. For
example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".

Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".

Minus signs ('-') are interpreted only if they are the first character of the
string.

Your function must be declared as follows:

int        ft_atoi_base(const char *str, int str_base);
*/

int        ft_atoi_base(const char *str, int str_base)
{
    int n;
    int i;
    int sign;
    int num;

    if (!str || (str_base < 2 || str_base > 16))
        return (0);
    i = 0;
    num = 0;
    sign = 1;
    while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' ||
            str[i] == '\f' || str[i] == ' ' || str[i] == '\r')
        ++i;
    if ((str[i] =='-' || str[i] == '+') && str[i++] == '-')
        sign *= -1;
    while (str[i])
    {
        n = str[i];
        if (n >= '0' && n <= '9')
            n -= '0';
        else if (n >= 'a' && n <= 'f')
            n -= 'a' - 10;
        else if (n >= 'A' && n <= 'F')
            n -= 'A' - 10;
        else 
            return (0);
        num = num * str_base + n;
        ++i;
    }
    return (sign * num);
}