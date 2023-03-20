/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_alpha.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 20:16:07 by vokrut            #+#    #+#             */
/*   Updated: 2019/09/03 08:35:39 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : count_alpha
Expected files   : count_alpha.c
Allowed functions: write, printf
--------------------------------------------------------------------------------

Write a program called count_alpha that takes a string and displays the number
of occurences of its alphabetical characters. Other characters are not counted.
The order is the order of occurence in the string. The display must be ended by
a newline.

The format is in the examples.

If the number of arguments is not 1, display only a newline.

Examples :
$> ./count_alpha abbcc
1a, 2b, 2c
$> ./count_alpha "abbcc"
1a, 2b, 2c
$> ./count_alpha "abbcc" "dddeef" | cat -e
$
$> ./count_alpha "My Hyze 47y 7." | cat -e
1m, 3y, 1h, 1z, 1e$
$> ./count_alpha "" | cat -e
$ */

#include <stdio.h>
#include <unistd.h>

char *str_to_lower(const char *string)
{
    char *str;

    str = (char*)string;
    int i = 0;
    while(str[i])
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
        i++;
    }
    return (str);
}

int count_letter(char *str, char ch)
{
    int count = 0;
    int i = 0;

    while(str[i])
    {
        if (str[i] == ch)
            count++;
        ++i;
    }
    return (count);
}

void count_alpha(char *str)
{
    int alpha[128] = {0};
    int flag;
    int i;

    flag = 1;
    i = 0;
    while(str[i])
    {
        if (str[i] >= 'a' && str[i] <= 'z' && !alpha[(int)str[i]])
        {
            alpha[(int)str[i]] = 1;
            if (!flag)
                printf(", ");
            flag = 0;
            printf("%d%c", count_letter(str, str[i]), str[i]);
        }
        i++;
    }
}

int main(int argc, char **av)
{
    char *str;

    if (argc == 2)
    {
        str = str_to_lower(av[1]); 
        count_alpha(str);
    }
    printf("\n");
    return (0);
}
