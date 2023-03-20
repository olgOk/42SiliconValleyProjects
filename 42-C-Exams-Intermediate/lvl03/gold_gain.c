/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gold_gain.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 17:00:40 by vokrut            #+#    #+#             */
/*   Updated: 2020/01/07 17:01:41 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Assignment name  : gold_gain
// Expected files   : gold_gain.c
// Allowed functions: malloc
// --------------------------------------------------------------------------------

// ALERT: OPTIMIZED SOLUTION REQUIRED.

// Given a matrix which represent a gold mine of n*n dimensions.
// Each field in this mine contains a positive integer which is the
// amount of gold in tons.

// Initially the miner is at first column but can be at any row.

// He can move only (right->,right up /,right down\) that is from a given cell,
// the miner can move to the cell diagonally up towards the right or right or
// diagonally down towards the right.

// implement an algorithm able to return the maximum amount of gold he can collect.

// The function must be declared as follows:

// int	gold_gain(int **mine, int n);

// Considerations:

// - Be careful: the brute force solution won't work on our big input, you have to
// find an optimized solution which use dynamic programming.
// - You don't have to handle error case, the matrix will be always squared.
// - The bigger test we will do is on matrix of 1 000 * 1 000,
// it should run in less than 2 seconds.

// Example 1:

// mine = [
//   [ 1, 0, 0 ],
//   [ 0, 3, 4 ],
//   [ 0, 0, 0 ]
// ]

// n = 3

// In this example, your function should return 8,
// because taking the following path gain 8:
// (0,0) -> (1,1) -> (1,2)
//   1   ->   3   ->   4

// Example 2:

// mine = [
//   [ 1, 2, 3 ],
//   [ 3, 4, 8 ],
//   [ 9, 6, 7 ]
// ]

// n = 3

// In this example, your function should return 23,
// because taking the following path gain 23:
// (2,0) -> (2,1) -> (1,3)


// Example 3:

// mine = [
//   [ 1, 3, 1, 5 ],
//   [ 2, 2, 4, 1 ],
//   [ 5, 0, 2, 3 ],
//   [ 0, 6, 1, 2 ]
// ]

// n = 4

// In this example, your function should return 16,
// because there is 2 path which give this gain:
// (2,0) -> (1,1) -> (1,2) -> (0,3)
// or
// (2,0) -> (3,1) -> (2,2) -> (2,3)

#include <stdlib.h>
#include <stdio.h>

int	gold_gain(int **mine, int n)
{
    int i = n - 2;
    int j = 0;
    int max_curr;
    int score = 0;
    if (n <= 0)
        return (0);
    if (n == 1)
        return (mine[0][0]);
    while(i >= 0)
    {
        j = 0;
        while(j < n)
        {
            max_curr = 0;
            if(j != 0 && mine[j - 1][i + 1] > max_curr)
                max_curr = mine[j - 1][i + 1];
            if (mine[j][i + 1] > max_curr)
                max_curr = mine[j][i + 1];
            if (j != n - 1 && mine[j + 1][i + 1] > max_curr)
                max_curr = mine[j + 1][i + 1];
            mine[j][i] += max_curr;
            if( i == 0 && mine[j][i] > score)
                score = mine[j][i];
            ++j;
        }
        --i;
    }
    return (score);
}



//testing, remove before submiting
int **convert_mine(int n, int mine[4][4])
{
    int **true_mine;
    int i;
    int j;

    true_mine = (int **)malloc(sizeof(int *) * n);
    i = 0;
    while (i < n)
    {
        true_mine[i] = (int *)malloc(sizeof(int) * n);
        j = 0;
        while (j < n)
        {
            true_mine[i][j] = mine[i][j];
            ++j;
        }
        ++i;
    }
    return (true_mine);
}

void    print_mine(int n, int **mine)
{
    int i;
    int j;

    i = 0;
    while (i < n)
    {
        j = 0;
        while (j < n)
        {
            printf("%3d", mine[i][j]);
            ++j;
        }
        printf("\n");
        ++i;
    }
}

int main()
{
    int n = 4;
    int mine[4][4] = {
        { 1, 3, 1, 5 },
        { 2, 2, 4, 1 },
        { 5, 0, 2, 3 },
        { 0, 6, 1, 2 }
        };

    // int n = 3;
    // int mine[3][3] = {
    //     { 1, 2, 3 },
    //     { 3, 4, 8 },
    //     { 9, 6, 7 }
    //     };

    // int n = 3;
    // int mine[3][3] = {
    //     { 1, 0, 0 },
    //     { 0, 3, 4 },
    //     { 0, 0, 0 }
    //     };

    int **true_mine = convert_mine(n, mine);

    print_mine(n, true_mine);
    printf("\n");
    int answer = gold_gain(true_mine, n);
    print_mine(n, true_mine);

    printf ("%d\n", answer);
}
