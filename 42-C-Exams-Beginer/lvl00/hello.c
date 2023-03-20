/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hello.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 18:00:19 by vokrut            #+#    #+#             */
/*   Updated: 2019/03/05 18:00:58 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Assignment name  : hello
Expected files   : hello.c
Allowed functions: write
--------------------------------------------------------------------------------
Write a program that displays "Hello World!" followed by a \n.
Example:

$>./hello
Hello World!
$>./hello | cat -e
Hello World!$
$>
*/ 

# include <unistd.h>

 int main(void)
{
       write(1, “Hello World!\n”, 13);
       return (0);
}
