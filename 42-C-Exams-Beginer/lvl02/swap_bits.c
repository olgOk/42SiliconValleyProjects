/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 20:02:50 by vokrut            #+#    #+#             */
/*   Updated: 2019/03/23 20:03:12 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : swap_bits
Expected files   : swap_bits.c
Allowed functions:
--------------------------------------------------------------------------------
Write a function that takes a byte, swaps its halves (like the example) and
returns the result. Your function must be declared as follows:
unsigned char        swap_bits(unsigned char octet);
Example:

  1 byte
_____________
 0100 | 0001
     \ /
     / \
 0001 | 0100
 */

unsigned char swap_bits(unsigned char octet)
{
     return ((octet >> 4) | (octet << 4));
}