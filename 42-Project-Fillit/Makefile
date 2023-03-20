# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/12 14:09:25 by vokrut            #+#    #+#              #
#    Updated: 2019/03/20 19:39:20 by vokrut           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asarafan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/12 13:49:37 by asarafan          #+#    #+#              #
#    Updated: 2019/03/12 13:57:53 by asarafan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = fillit.c valid_input.c cleaning.c algorithm.c additional.c additionalsec.c

INCL = fillit.h

LIBFT = libft/libft.a

all: $(NAME)

$(NAME): 
	make -C libft
	$(CC) $(CFLAGS) -I $(INCL) $(SRC) $(LIBFT) -o $(NAME)

clean:
	make -C libft clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C libft fclean
	
re: fclean all
