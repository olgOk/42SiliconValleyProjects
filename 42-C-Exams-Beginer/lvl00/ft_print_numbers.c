/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 17:47:32 by vokrut            #+#    #+#             */
/*   Updated: 2019/03/05 17:48:28 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Assignment name  : ft_print_numbers
Expected files   : ft_print_numbers.c
Allowed functions: write
----------------------------------------------
Write a function that displays all digits in ascending order.
Your function must be declared as follows: void        ft_print_numbers(void);
*/

#include <unistd.h>

void ft_print_numbers(void)
{
       write(1, “0123456789”, 10);
}