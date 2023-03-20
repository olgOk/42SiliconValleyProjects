/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_of_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 12:01:12 by vokrut            #+#    #+#             */
/*   Updated: 2019/06/23 12:18:14 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			find_twos(int i)
{
	int		count;

	count = 0;
	while (i > 9)
	{
		if (i % 10 == 2)
			++count;
		i = i / 10;
	}
	if (i == 2)
		++count;
	return (count);
}

int			count_of_2(int n)
{
	int		i;
	int		count;

	i = 2;
	count = 0;
	while (i <= n)
	{
		count += find_twos(i);
		++i;
	}
	return (count);
}


/*remove later*/
#include <stdio.h>
int main(void)
{
    printf("%d\n", count_of_2(25)); //9
    printf("%d\n", count_of_2(1)); //0
    printf("%d\n", count_of_2(5)); //1
    printf("%d\n", count_of_2(30)); //13
    return (0);
}    
