/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   only_z.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 17:33:20 by vokrut            #+#    #+#             */
/*   Updated: 2019/03/05 17:47:07 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Assignment name  : only_z
Expected files   : only_z.c
Allowed functions: write
----------------------------------------------
Write a program that displays a 'z' character on the standard output
*/

#include <unistd.h>

int main(void)
{
      write(1, "z", 1);
      return (0);
}