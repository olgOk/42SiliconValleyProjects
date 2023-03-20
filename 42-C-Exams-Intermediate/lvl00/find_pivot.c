/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pivot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 12:20:49 by vokrut            #+#    #+#             */
/*   Updated: 2019/06/23 13:29:36 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int find_pivot(int *arr, int n)
{
    int sum;
    int left_sum;
    int i;

    sum = 0;
    i = 0;
    while (i < n)
        sum += arr[i++];
    i = 0;
    left_sum = 0;
    while (i < n)
    {
        if (left_sum == (sum - left_sum - arr[i]))
            return (i);
        left_sum += arr[i];
        ++i;
    }
    return (-1);
}

/*remove*/
#include <stdio.h>
int main(void)
{
    int arr[6] = ( 1, 2, 3, 4, 0, 6 );
    int arr1 = (-5, 10, 2, 5);
    int arr2 = (1, 100, 0, 0, 1 );
    int arr3 = (7, 9, 8);
    int arr4 = (1, 2);

    printf("%d\n", find_pivot(arr, 6)); //3
    printf("%d\n", find_pivot(arr1, 4)); //2
    printf("%d\n", find_pivot(arr2, 5)); //1
    printf("%d\n", find_pivot(arr3, 3)); //-1
    printf("%d\n", find_pivot(arr4, 2)); //-1
}
