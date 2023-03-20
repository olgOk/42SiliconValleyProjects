/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 10:43:01 by vokrut            #+#    #+#             */
/*   Updated: 2019/03/06 20:34:09 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Assignment name  : ft_strdup
Expected files   : ft_strdup.c
Allowed functions: malloc
--------------------------------------------------------------------------------
Reproduce the behavior of the function strdup (man strdup).
Your function must be declared as follows: char    *ft_strdup(char *src);*/

#include <stdlib.h>

char        *ft_strdup(char *src)
{
    char        *dup;
    char        *sptr;
    char        *dptr;

    sptr = src;
    while (*sptr++)
        ;
    dup = malloc(sptr - src + 1);
    if (!dup)
        return (NULL);
    dptr = dup;
    while ((*dptr++ = *src++))
        ;
    return (dup);
}