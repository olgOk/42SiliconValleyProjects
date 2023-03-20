/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 21:06:39 by vokrut            #+#    #+#             */
/*   Updated: 2019/03/06 21:21:35 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Assignment name  : max
Expected files   : max.c
Allowed functions:
--------------------------------------------------------------------------------
Write the following function:

int        max(int* tab, unsigned int len);

The first parameter is an array of int, the second is the number of elements in
the array.
The function returns the largest number found in the array.
If the array is empty, the function returns 0.          */

int    max(int* tab, unsigned int len)
{
    int             max;
    unsigned int    i;

    if (!tab)
        return (0);
    max = tab[0];
    i = 1;
    while (i < len)
    {
        if (tab[i] > max)
        max = tab[i];
        i++;
    }
    return (max);
}