/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pivot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 12:20:49 by vokrut            #+#    #+#             */
/*   Updated: 2019/08/19 12:14:58 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : find_pivot
Expected files   : find_pivot.c
Allowed functions: 
--------------------------------------------------------------------------------

ALERT: OPTIMIZED SOLUTION REQUIRED.

Given an array of integers and its size passed as parameters,
create a function able to return the pivot index of this array.
The pivot index is the index where the sum of the numbers on the left
is equal to the sum of the numbers on the right.

The function must be declared as follows:

	int	find_pivot(int *arr, int n);

If there is no pivot present, return -1.

Considerations:

- Be careful: the naive solution won't work on our big input, you have to
find an optimized solution which will run in O(n) time (where n is the
length of the array). 
- The array will always have a length bigger than 1.
- You don't have to take care of overflow or underflow of sums,
it will stay in an range of an int.
- The bigger test we will do is on an array of 1.000.000 elements.
It should run in less than 2 seconds.
 
Example 1:

	arr = [ 1, 2, 3, 4, 0, 6 ] , n = 6

In this case, your function should return 3.

Because at index 3, the sum of the elements on the left is equals
to the sum of the elements on the right:
 
    = 6        = 6
  _______     ____
[ 1, 2, 3, 4, 0, 6 ]
           ^
           |
     with pivot = 3

Example 2: 

arr = [ -5, 10, 2, 5 ] , n = 4

In this case, your function should return 2.

Example 3:

arr = [ 1, 100, 0, 0, 1 ] , n = 5

In this case, your function should return 1.

Example 4:

arr = [ 7, 9, 8 ] , n = 3

In this case, your function should return -1.

Example 5:

arr = [ 1 , 2 ] , n = 2

In this case, your function should return -1. */

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