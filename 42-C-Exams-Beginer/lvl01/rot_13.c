/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 18:34:00 by vokrut            #+#    #+#             */
/*   Updated: 2019/03/05 18:34:41 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Assignment name  : rot_13
Expected files   : rot_13.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays it, replacing each of its
letters by the letter 13 spaces ahead in alphabetical order.

'z' becomes 'm' and 'Z' becomes 'M'. Case remains unaffected.

The output will be followed by a newline.

If the number of arguments is not 1, the program displays a newline.

Example:

$>./rot_13 "abc"
nop
$>./rot_13 "My horse is Amazing." | cat -e
Zl ubefr vf Nznmvat.$
$>./rot_13 "AkjhZ zLKIJz , 23y " | cat -e
NxwuM mYXVWm , 23l $
$>./rot_13 | cat -e
$
$>
$>./rot_13 "" | cat -e
$
$>
*/

int                main(int argc, char *argv[])
{
    int i;

    i = 0;
    while (argc == 2 && argv[1][i])
    {
        if (('A' <= argv[1][i] && 'M' >= argv[1][i])
            || ('a' <= argv[1][i] && 'm' >= argv[1][i]))
        {
            argv[1][i] += 13;
            write(1, &argv[1][i], 1);
        }
        else if (('N' <= argv[1][i] && 'Z' >= argv[1][i])
                || ('n' <= argv[1][i] && 'z' >= argv[1][i]))
        {
            argv[1][i] -= 13;
            write(1, &argv[1][i], 1);
        }                               
        else
            write(1, &argv[1][i], 1);
        i++;
    }
    write(1, "\n", 1);
    return (0);
}