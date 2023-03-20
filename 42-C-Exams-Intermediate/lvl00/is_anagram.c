/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_anagram.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 18:29:31 by vokrut            #+#    #+#             */
/*   Updated: 2019/06/23 20:11:14 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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