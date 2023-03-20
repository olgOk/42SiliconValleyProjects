/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 21:22:13 by vokrut            #+#    #+#             */
/*   Updated: 2019/03/06 21:23:39 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Assignment name  : print_bits
Expected files   : print_bits.c
Allowed functions: write
--------------------------------------------------------------------------------
Write a function that takes a byte, and prints it in binary WITHOUT A NEWLINE
AT THE END.
Your function must be declared as follows:
void        print_bits(unsigned char octet);
Example, if you pass 2 to print_bits, it will print "00000010"              */

#include <unistd.h>
void print_bits(unsigned char octet)
{
   unsigned char num;
    num = 128;
    while (num)
    {
        if (octet & num)
            write(1, "1", 1);
        else
            write(1, "0", 1);
        num = num >> 1;
    }
}