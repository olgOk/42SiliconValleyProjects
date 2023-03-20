/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 19:48:05 by vokrut            #+#    #+#             */
/*   Updated: 2019/03/29 22:05:15 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Assignment name  : str_capitalizer
Expected files   : str_capitalizer.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes one or several strings and, for each argument,
capitalizes the first character of each word (If it's a letter, obviously),
puts the rest in lowercase, and displays the result on the standard output,
followed by a \n.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string. If a word only has one letter, it must be
capitalized.

If there are no arguments, the progam must display \n.

Example:

$> ./str_capitalizer | cat -e
$
$> ./str_capitalizer "Premier PETIT TesT" | cat -e
Premier Petit Test$
$> ./str_capitalizer "DeuxiEmE tEST uN PEU moinS  facile"
"   attention C'EST pas dur QUAND mEmE" "ALLer UN DeRNier 0123456789pour
LA rouTE    E " | cat -e
Deuxieme Test Un Peu Moins  Facile$
   Attention C'est Pas Dur Quand Meme$
Aller Un Dernier 0123456789pour La Route    E $
$>
*/
#include <unistd.h>

void	ft_putstr(char const *s)
{
	unsigned int i;

	if (s)
	{
		i = 0;
		while (s[i])
			write(1, &s[i++], 1);
	}
}

void	ft_strcapitalize(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	if (str[0] != '\0' && str[0] >= 'a' && str[0] <= 'z')
		str[0] -= 32;
	i = 0;
	while (str[i])
	{
		i++;
		if (str[i] < 64 || str[i] > 127 )
			continue ;
		else if (str[i - 1] == ' ' || str[i - 1] == '-' || str[i - 1] == '+')
			str[i] -= 32;
	}
	ft_putstr(str);
}

int        main(int argc, char **argv)
{
    int        i;

    i = 0;
    if (argc > 1)
    {
        while (++i < argc)
        {
            ft_strcapitalize(argv[i]);
            write(1, "\n", 1);
        }
    }
    else
        write(1, "\n", 1);
    return (0);
}