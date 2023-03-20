# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/02 18:49:54 by vokrut            #+#    #+#              #
#    Updated: 2019/05/02 18:54:54 by vokrut           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc

CFLAGS = -Wall -Werror -Wextra

MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

SRC = ./src/fdf.c ./src/ft_read_file.c ./src/ft_modificate.c
SRC += ./src/ft_helper.c ./src/ft_cartesian.c ./src/ft_draw_line.c
SRC += ./src/ft_to_iso.c ./src/ft_draw.c ./src/ft_keyboard.c
SRC += ./src/ft_colors.c ./src/ft_free.c

LIBFT = libft

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJ)
		Make -C libft
		Make -C minilibx_macos
		$(CC) $(CFLAGS) -I ft_fdf.h libft/libft.a -L ./minilibx_macos \
				$(MLXFLAGS) $(SRC) -o $(NAME)

$(OBJ): $(LIBFT)
		gcc -Wall -Werror -Wextra -g -c $(SRC)

clean :
		-rm -f $(OBJ)
		make clean -C libft
				
fclean : clean
		-rm -f $(NAME)
		make fclean -C libft
		
re : fclean all