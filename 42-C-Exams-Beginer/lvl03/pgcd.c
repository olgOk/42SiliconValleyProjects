/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 13:16:26 by vokrut            #+#    #+#             */
/*   Updated: 2019/03/29 13:16:44 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>


int        main(int argc, char const *argv[])
{
    int        num1;
    int        num2;
    
    if (argc == 3)
    {
        num1 = atoi(argv[1]);
        num2 = atoi(argv[2]);
        if (num1 > 0 && num2 > 0)
        {
            while (num1 != num2)
            {
                if (num1 > num2)
                    num1 = num1 - num2;
                else
                    num2 = num2 - num1;
            }
        }
        printf("%d", num1);
    }
    printf("\n");
    return (0);
}