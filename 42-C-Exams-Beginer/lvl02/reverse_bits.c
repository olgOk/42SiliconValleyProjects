/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 20:00:48 by vokrut            #+#    #+#             */
/*   Updated: 2019/03/23 20:02:35 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : reverse_bits
Expected files   : reverse_bits.c
Allowed functions:
--------------------------------------------------------------------------------
Write a function that takes a byte, reverses it, bit by bit (like the
example) and returns the result   Your function must be declared as follows:
unsigned char        reverse_bits(unsigned char octet);
Example:

  1 byte
_____________
 0100  0001
     ||
     \/
 1000  0010
*/

unsigned char reverse_bits(unsigned char octet)
{
     unsigned char rev_num;
     int i;
      
      i = 8;
      rev_num = 0;
      while (i > 0)
      {
           rev_num = (rev_num  << 1) | (octet & 1);
           octet = octet >> 1;
           i--;
      }
      return (rev_num);
}