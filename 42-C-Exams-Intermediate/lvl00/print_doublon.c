/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_doublon.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 13:31:32 by vokrut            #+#    #+#             */
/*   Updated: 2019/06/23 18:28:00 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void    print_doublon(int *a, int na, int *b, int nb)
{
    int ia;
    int jb;
    int flag;

    ia = 0;
    jb = 0;
    flag = 0;
    while(ia < na && jb < nb)
    {
        if (a[ia] == b[jb])
        {
            printf("%s%d", flag == 1 ? " " : "", a[ia]);
            flag = 1;
        }
        (b[jb] < a[ia]) ? (jb++) : (ia ++); 
    }
    printf("\n");
}

/*remove*/
int main(void)
{
    int a[4] = {1,2,10,15};
    int b[4] = {2,20,40,70};

    int arr1[11] = {-5,  2, 10, 15, 50, 70, 100, 200, 300, 1200, 5000};
    int arr2[8] = {2,  4,  5,  6,  7, 10,  40,  70};

    int arra[3] = {100,  200, 300};
    int arrb[4] = {1,  2, 3, 4};

    print_doublon(a, 4, b, 4); //2
    printf("============");
    print_doublon(arr1, 11, arr2, 8); // 2 10 70
    printf("============");
    print_doublon(arra, 3, arrb, 4); //new line
    printf("============");
}