/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 18:26:24 by vokrut            #+#    #+#             */
/*   Updated: 2019/03/05 18:27:06 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Assignment name  : ft_strlen
Expected files   : ft_strlen.c
Allowed functions:
----------------------------------------------------
Write a function that returns the length of a string. Your function must be declared as follows: 
int        ft_strlen(char *str); */

int        ft_strlen(char *str)
{
    unsigned int len;

    len = 0;
    while (*str++)
        len++;
    return (len);
}