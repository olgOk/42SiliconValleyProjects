/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countdown.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 17:48:49 by vokrut            #+#    #+#             */
/*   Updated: 2019/03/05 17:49:35 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Assignment name  : ft_countdown
Expected files   : ft_countdown.c
Allowed functions: write
----------------------------------------------
Write a program that displays all digits in descending order, followed by a newline.
Example:
$> ./ft_countdown | cat -e
9876543210$
$>
*/

#include <unistd.h>

int main(void)
{
      write(1, “9876543210\n”, 11);
      return (0);
}