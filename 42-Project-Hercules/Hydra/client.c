/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 00:22:09 by vokrut            #+#    #+#             */
/*   Updated: 2019/03/09 16:49:53 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>

int main(int ac, char *av[])
{
    int                 sock;
    char                buf[256];
    struct sockaddr_in  addr;

    printf("\033[1;34m");
    if (ac != 3)
	{
		printf("Please, provide [IP] and [PORT]\n");
		return (0);
	}
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        printf("Could not create a socket\n");
        return (0);
    }
    printf("Socket has been successfully created\n");
    addr.sin_family = AF_INET;
    addr.sin_port = htons(atoi(av[2]));
    addr.sin_addr.s_addr = inet_addr(av[1]);
    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        printf("Could not connect\n");
        return (0);
    }
    printf("Establishing connection...\n");
    printf("Enter message: ");
	bzero(buf, 256);
	fgets(buf, 255, stdin);
	if (send(sock, buf, strlen(buf), 0) == -1)
    {
        printf("Error occured while sending the message!\n");
        return (0);
    }
    printf("Message has been send\n");
	bzero(buf, 256);
	if (recv(sock, buf, 50, 0) <= 0)
    {
        printf("Error occured while recieving the message\n");
        return (0);
    }
	buf[50] = '\0';
	printf("You have new message: %s", buf);
	close(sock);
	return (0);
}