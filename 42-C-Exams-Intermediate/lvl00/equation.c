/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 11:46:02 by vokrut            #+#    #+#             */
/*   Updated: 2019/06/23 12:00:48 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void    equation(int n)
{
    int num;
    int a;
    int b;
    int c;

    a = 0;
    while(a <= 9) 
    {
        b = 0;
        while(b <= 9)
        {
            c = 0;
            while(c <= 9)
            {
                num = (a * 10 + b) + (c * 10 + a);
                if (num == n)
                    printf("A = %d, B = %d, C = %d\n", a, b, c);
                c++;
            }
            b++;
        }
        a++;
    }
}

/*remove later*/
int main(void)
{
    equation(42);
    printf("\n========\n");
    equation(111);
    printf("\n========\n");
    equation(0);

}