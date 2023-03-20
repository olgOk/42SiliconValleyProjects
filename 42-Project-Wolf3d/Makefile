# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/21 20:38:39 by vokrut            #+#    #+#              #
#    Updated: 2019/08/23 17:38:35 by vokrut           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCLUDES = -I ./includes
MINILIBX_INCLUDES = -I ./minilibx_macos

LIBFT = libft/libft.a

SRCS =	./srcs/main.c \
		./srcs/ft_main_call.c \
		./srcs/read_map.c \
		./srcs/raycasting.c \
		./srcs/raycasting_extra_functions.c \
		./srcs/ft_keyboard.c \
		./srcs/ft_movement.c \
		./srcs/ft_wall_collision.c \
		./srcs/ft_quadrant.c \
		./srcs/ft_draw_map_navigation.c \
		./srcs/ft_draw_grid_and_map.c \
		./srcs/ft_textures.c \
		./utils/struct_operations/t_list.c

OBJ = $(SRCS:.c=.o)

EXEC = wolf3d

RESET = \033[0m
RED = \033[0;31m
GREEN = \033[0;32m
BLUE = \033[0;36m
RED_EXTRA = \033[1;31m
GREEN_EXTRA = \033[1;32m
BLUE_EXTRA = \033[1;36m

%.o:%.c
	@echo "$(GREEN) - Creating $(GREEN_EXTRA)$<...$(RESET)"
	@gcc -Wall -Wextra -Werror -g  -c $< -o $@ $(INCLUDES)

all: $(EXEC)

$(EXEC): $(OBJ)
	@echo "$(GREEN)Making objects files for $(GREEN_EXTRA)$(EXEC)$(RESET)"
	@make -C libft
	@echo "$(GREEN)Compiling executable $(GREEN_EXTRA)$(EXEC)$(RESET)"
	@gcc -Wall -Wextra -Werror $(OBJ_CALC) $(OBJ) $(LIBFT) $(INCLUDES) $(MINILIBX_INCLUDES) -L minilibx_macos -lmlx -framework OpenGL -framework AppKit -o $(EXEC) -g #-fsanitize=address
	@echo "$(BLUE_EXTRA)$(EXEC)$(BLUE): Complete$(RESET)"

clean:
	@if [ -a "srcs/main.o" ]; then \
	echo "$(RED)Deleting objects for $(RED_EXTRA)$(EXEC)$(RESET)"; \
	/bin/rm -rf $(OBJ); \
	fi
	@make -C libft clean
	@echo "$(BLUE_EXTRA)clean$(BLUE): Complete$(RESET)"

fclean: clean
	@if [ -a "$(EXEC)" ]; then \
	echo "$(RED)Deleting executable $(RED_EXTRA)$(EXEC)$(RESET)"; \
	/bin/rm -f $(EXEC); \
	fi
	@make -C libft fclean
	@echo "$(BLUE_EXTRA)fclean$(BLUE): Complete$(RESET)"

re: fclean all
