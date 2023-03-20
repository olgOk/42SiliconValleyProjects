/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_anagram.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 18:29:31 by vokrut            #+#    #+#             */
/*   Updated: 2019/08/19 12:20:26 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : is_anagram
Expected files   : is_anagram.c
Allowed functions: 
--------------------------------------------------------------------------------

ALERT: OPTIMIZED SOLUTION REQUIRED.

An anagram is a sequence of characters formed by rearranging the letters of
another sequence, such as 'cinema', formed from 'iceman'.

Given two strings as parameters, create a function able to tell whether or
not the first string is an anagram of the second.

The function must be declared as follows:

int	is_anagram(char *a, char *b);

Considerations:

- Be careful: the naive solution won't work on our big input, you have to
find an optimized solution which will run in O(sa + sb) time (where sa is
the length of a and sb length of b).
- Our tested string will always be a sequence of ascii characters between 32
and 126 inclusive.
- The bigger test we will do is on 2 sequences of 1.000.000 characteres each.
It should run in less than 2 seconds.

Example 1:

a='abcdef'
b='fabcde'

In this case, these two strings are anagrams, your function should return 1.

Example 2: 

a='.123?.'
b='?321..'

In this case, these two strings are anagrams, your function should return 1.

Example 3:

a='abca'
b='bcab'

In this case, these two strings are not anagrams, your function should return 0. */

int is_anagram(char *a, char *b)
{
    int temp[127] = {0};
    int i = 0;

    while(a[i])
        temp[(unsigned int)a[i++]] += 1;
    i = 0;
    while(b[i])
        temp[(unsigned int)b[i++]] -= 1;
    i = 0;
    while(i < 127)
        if (temp[i++] != 0)
            return (0);
    return (1);
}

/*remove*/
#include <stdio.h>
int main(void)
{
    char a1[] = "abcdef";
    char b1[] = "fabcde";

    char a2[] = ".123?.";
    char b2[] = "?321..";

    char a3[] = "abca";
    char b3[] = "bcab";

    if (is_anagram(a1, b1))
        printf("%s and %s is anagram\n", a1, b1);
    else 
        printf("%s and %s is NOT anagram\n", a1, b1);

    printf("======\n");
    if (is_anagram(a2, b2))
        printf("%s and %s is anagram\n", a2, b2);
    else 
        printf("%s and %s is NOT anagram\n", a2, b2);
    printf("======\n");
    if (is_anagram(a3, b3))
        printf("%s and %s is anagram\n", a3, b3);
    else 
        printf("%s and %s is NOT anagram\n", a3, b3);
    printf("======\n");
    return (0);
}