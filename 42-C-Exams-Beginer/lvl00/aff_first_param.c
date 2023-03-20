/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_first_param.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 17:57:33 by vokrut            #+#    #+#             */
/*   Updated: 2019/03/05 17:59:39 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Assignment name  : aff_first_param
Expected files   : aff_first_param.c
Allowed functions: write
----------------------------------------------------
Write a program that takes strings as arguments, and displays its first
argument followed by a \n.

If the number of arguments is less than 1, the program displays \n.

Example:
$> ./aff_first_param vincent mit "l'ane" dans un pre et "s'en" vint | cat -e
vincent$
$> ./aff_first_param "j'aime le fromage de chevre" | cat -e
j'aime le fromage de chevre$
$> ./aff_first_param
$
*/

#include <unistd.h>

int main(int argc, char **argv)
{
    int i;

    i = 0;
    while (argc > 1 && argv[1][i])
        write(1, &argv[1][i++], 1);
    write (1, "\n", 1);
    return (0);
}
