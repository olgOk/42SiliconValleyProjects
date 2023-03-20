/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 20:03:49 by vokrut            #+#    #+#             */
/*   Updated: 2019/03/24 22:17:26 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : union
Expected files   : union.c
Allowed functions: write
--------------------------------------------------------------------------------
Write a program that takes two strings and displays, without doubles, the
characters that appear in either one of the strings.
The display will be in the order characters appear in the command line, and
will be followed by a \n.
If the number of arguments is not 2, the program displays \n.
Example:

$>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
zpadintoqefwjy$
$>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6vewg4thras$
$>./union "rien" "cette phrase ne cache rien" | cat -e
rienct phas$
$>./union | cat -e
$
$>
$>./union "rien" | cat -e
$
$>
*/

#include<unistd.h>

int		main(int argc, char **argv)
{
	int		i;
	char	temp[127] = {0};

	if (argc == 3)
	{
		i = 0;
		while (argv[1][i])
		{
			if (temp[(int)argv[1][i]] == 0)
			{
				write(1, &argv[1][i], 1);
				temp[(int)argv[1][i]] = 1;
			}
			i++;
		}
	    i = 0;
	    while (argv[2][i])
	    {
		    if (temp[(int)argv[2][i]] == 0)
		    {
			    write(1,&argv[2][i],1);
			    temp[(int)argv[2][i]]=1;
		    }
		    i++;
	    }
	}
write (1, "\n", 1);
return (0);
}



