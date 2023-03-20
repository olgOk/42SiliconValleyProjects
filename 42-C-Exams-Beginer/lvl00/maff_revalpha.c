/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maff_revalpha.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 17:39:59 by vokrut            #+#    #+#             */
/*   Updated: 2019/03/05 17:47:00 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Assignment name  : maff_revalpha
Expected files   : maff_revalpha.c
Allowed functions: write
----------------------------------------------
Write a program that displays the alphabet in reverse, with even letters in
uppercase, and odd letters in lowercase, followed by a newline.

Example:
$> ./maff_revalpha | cat -e
zYxWvUtSrQpOnMlKjIhGfEdCbA$
*/

int main(void)
{
      write(1, “zYxWvUtSrQpOnMlKjIhGfEdCbA\n”, 27);
      return (0);
}