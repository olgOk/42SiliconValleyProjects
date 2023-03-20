/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 18:22:41 by vokrut            #+#    #+#             */
/*   Updated: 2019/03/05 18:25:49 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
Assignment name  : ft_strcpy
Expected files   : ft_strcpy.c
Allowed functions: 
----------------------------------------------------
Reproduce the behavior of the function strcpy (man strcpy). 
Your function must be declared as follows: char    *ft_strcpy(char *s1, char *s2); 
*/

char        *ft_strcpy(char *s1, char *s2)
{
        int i;

        i = 0;
        while (s1[i] = s2[i])
          i++;
        s1[i] = s2[i];
        return (s1);
}
