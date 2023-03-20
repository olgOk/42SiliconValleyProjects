/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   only_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 17:37:14 by vokrut            #+#    #+#             */
/*   Updated: 2019/03/05 17:46:58 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Assignment name  : only_a
Expected files   : only_a.c
Allowed functions: write
---------------------------------------------
Write a program that displays a 'a' character on the standard output.
*/

#include <unistd.h>

int main(void)
{
      write(1, "a", 1);
      return (0);
}
