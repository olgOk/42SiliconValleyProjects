/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 18:38:50 by vokrut            #+#    #+#             */
/*   Updated: 2019/03/05 18:39:03 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Assignment name  : rotone
Expected files   : rotone.c
Allowed functions: write
--------------------------------------------------------------------------------
Write a program that takes a string and displays it, replacing each of its
letters by the next one in alphabetical order.
'z' becomes 'a' and 'Z' becomes 'A'. Case remains unaffected.
The output will be followed by a \n.
If the number of arguments is not 1, the program displays \n.
Example:

$>./rotone "abc"
bcd
$>./rotone "Les stagiaires du staff ne sentent pas toujours tres bon." | cat -e
Mft tubhjbjsft ev tubgg of tfoufou qbt upvkpvst usft cpo.$
$>./rotone "AkjhZ zLKIJz , 23y " | cat -e
BlkiA aMLJKa , 23z $
$>./rotone | cat -e
$
$>
$>./rotone "" | cat -e
$
$>
*/

#include <unistd.h>

int                main(int argc, char **argv)
{
    int i;

    
    while (argc == 2 && argv[1][i])
    {
        if ((argv[1][i] >= 'A' && argv[1][i] <= 'Y')  ||
            (argv[1][i] >= 'a' && argv[1][i] <= 'y'))
        {
            argv[1][i] += 1;
            write(1, &argv[1][i], 1);
        }
        else if (argv[1][i] == 'z' || argv[1][i] == 'Z')
        {
            argv[1][i] -= 25;
            write(1, &argv[1][i], 1);
        }
        else
            write(1, &argv[1][i], 1);
        i++;
    }
        write(1, "\n", 1);
        return (0);
}