# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/02 18:49:54 by vokrut            #+#    #+#              #
#    Updated: 2019/05/15 10:28:07 by vokrut           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = gcc

CFLAGS = -Wall -Werror -Wextra

MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

SRC = ./src/fractol.c ./src/ft_helper.c ./src/ft_draw_fractal.c
SRC += ./src/ft_fractals.c ./src/ft_colors.c ./src/ft_bonus_fractal.c
SRC += ./src/ft_keyboard.c ./src/ft_mouse.c ./src/ft_die.c

LIBFT = libft

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
		Make -C libft
		Make -C minilibx_macos
		$(CC) $(CFLAGS) -I ./includes/ft_fractol.h libft/libft.a -L ./minilibx_macos \
				$(MLXFLAGS) $(SRC) -o $(NAME)

$(OBJ): $(LIBFT)
		gcc -Wall -Wextra -Werror -g -c $(SRC)
clean:
		-rm -f $(OBJ)
		make clean -C libft
				
fclean: clean
		-rm -f $(NAME)
		make fclean -C libft
		
re: fclean all