/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 20:35:00 by vokrut            #+#    #+#             */
/*   Updated: 2019/03/06 21:04:35 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Assignment name  : ft_strrev
Expected files   : ft_strrev.c
Allowed functions:
--------------------------------------------------------------------------------
Write a function that reverses (in-place) a string.
It must return its parameter. Your function must be declared as follows:
char    *ft_strrev(char *str);                                                */

char        *ft_strrev(char *str)
{
    int i; 
    int count;
    char temp;

    count = 0;
    while (*(str + count))
        count++;    
    i = -1;
    while (++i < --count)
    {
        temp = *(str + i);
        *(str + i) = *(str + count);
        *(str + count) = temp;
    }
    return (str);
}