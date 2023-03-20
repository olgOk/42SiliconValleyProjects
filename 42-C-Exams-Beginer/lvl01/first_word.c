/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 18:10:14 by vokrut            #+#    #+#             */
/*   Updated: 2019/03/05 18:18:17 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Assignment name  : first_word
Expected files   : first_word.c
Allowed functions: write
----------------------------------------------------
Write a program that takes a string and displays its first word, followed by a
newline. A word is a section of string delimited by spaces/tabs or by the start/end of the string.
If the number of parameters is not 1, or if there are no words, simply display
a newline.

Examples:
$> ./first_word "FOR PONY" | cat -e
FOR$
$> ./first_word "this        ...       is sparta, then again, maybe    not" | cat -e
this$
$> ./first_word "   " | cat -e
$
$> ./first_word "a" "b" | cat -e
$
$> ./first_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
$>
*/

#include <unistd.h>

int main(int ar, char **av)
{
    int i;

    i = 0;
    while (ar == 2 && *av[1] <= 32)
        av[1]++;
    while (ar == 2 && *av[1] > 32 && *av[1] < 127)
        write(1, &av[1], 1);
    write (1, "\n", 1);
    return (0);
}
