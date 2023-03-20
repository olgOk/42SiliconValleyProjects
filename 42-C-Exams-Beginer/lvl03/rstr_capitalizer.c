/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 19:46:24 by vokrut            #+#    #+#             */
/*   Updated: 2019/03/30 10:07:32 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Assignment name  : rstr_capitalizer
Expected files   : rstr_capitalizer.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes one or more strings and, for each argument, puts
the last character of each word (if it's a letter) in uppercase and the rest
in lowercase, then displays the result followed by a \n.

A word is a section of string delimited by spaces/tabs or the start/end of the
string. If a word has a single letter, it must be capitalized.

If there are no parameters, display \n.

Examples:

$> ./rstr_capitalizer | cat -e
$
$> ./rstr_capitalizer "Premier PETIT TesT" | cat -e
premieR petiT tesT$
$> ./rstr_capitalizer "DeuxiEmE tEST uN PEU moinS  facile" "   attention
C'EST pas dur QUAND mEmE" "ALLer UN DeRNier 0123456789pour LA rouTE    E " | cat -e
deuxiemE tesT uN peU moinS  facilE$
   attentioN c'esT paS duR quanD memE$
alleR uN dernieR 0123456789pouR lA routE    E $
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

void	rstr_capitalize(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	i = 0;
	while (str[i])
	{
		i++;
		if (str[i] < 64 || str[i] > 127 )
			continue ;
		else if (str[i] >= 'a' && str[i] <= 'z' && (str[i + 1] == ' '
                || str[i + 1] == '\t' || str[i + 1] == '\n' || str[i + 1] == '\r'
                || str[i + 1] == '\v' || str[i + 1] == '\f' || str[i + 1] == '\0'))
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
            rstr_capitalize(argv[i]);
            write(1, "\n", 1);
        }
    }
    else
        write(1, "\n", 1);
    return (0);
}