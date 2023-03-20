/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_doublon.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 13:31:32 by vokrut            #+#    #+#             */
/*   Updated: 2019/08/19 12:22:59 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : print_doublon
Expected files   : print_doublon.c
Allowed functions: printf
--------------------------------------------------------------------------------

ALERT: OPTIMIZED SOLUTION REQUIRED.

Given two sorted arrays passed as parameters,
create a function able to print all the number that are present
in one array and in the other, separated by a space.
Then print a new line.

The function must be declared as follows (with 'na' the length of the array 'a',
and 'nb' the length of the array 'b'):

void	print_doublon(int *a, int na, int *b, int nb);

Considerations:

- Be careful: the naive solution won't work on our big input, you have to
find an optimized solution which will run in O(n) time (where n is
the length of the longest array between a and b).
- All elements of an array are unique. The same number will not repeat in an array. 
- If there is no doublon, just print a new line '\n'.
- The bigger test we will run will be on 2 arrays of 500 000 elements each,
it should run in less than 2 seconds.

Example 1:

a = [ 1,  2, 10, 15 ] , na = 4
b = [ 2, 20, 40, 70 ] , nb = 4

In this case, by using a main file that use your function with the above input,
the output should be (using cat -e):

$> ./example1 | cat -e
2$

Example 2: 

a = [ -5,  2, 10, 15, 50, 70, 100, 200, 300, 1200, 5000 ] , na = 11
b = [  2,  4,  5,  6,  7, 10,  40,  70 ]                  , nb = 8 

In this case, by using a main file that use your function with the above input,
the output should be (using cat -e):

$> ./example2 | cat -e
2 10 70$

Example 3:

a = [ 100,  200, 300 ]    , na = 3
b = [   1,    2,   3, 4 ] , nb = 4

In this case, by using a main file that use your function with the above input,
the output should be (using cat -e):

$> ./example3 | cat -e
$ */

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