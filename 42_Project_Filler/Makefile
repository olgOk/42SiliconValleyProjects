# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user <user@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/14 11:38:28 by user              #+#    #+#              #
#    Updated: 2020/04/15 11:09:31 by user             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCLUDES = -I includes -I libft

SRS = 	srs/main.c \
		srs/parsing.c \
		srs/help_functions.c \
		srs/placement.c \
		srs/algorithm.c
		
LIBFT = -L ./libft -lft
LIB_FILLLER = lib_filler.a

OBJ		= $(SRS:.c=.o)

EXEC = vokrut.filler

all: $(EXEC)

$(EXEC):
	@gcc -Wall -Wextra -Werror $(SRS) $(INCLUDES) -c
	@ar rc $(LIB_FILLLER) *.o
	@ranlib $(LIB_FILLLER)
	# @make -C libft
	@gcc -Wall -Wextra -Werror $(LIB_FILLLER) $(LIBFT) $(INCLUDES) -o $(EXEC)
	
clean:
	# @make -C libft clean
	@rm -f *.o
	@echo "$(BLUE_EXTRA)clean$(BLUE): Complete$(RESET)"

fclean: clean
	# @make -C libft fclean
	@rm -f $(EXEC)
	@rm -f $(LIB_FILLLER)
	@echo "$(BLUE_EXTRA)fclean$(BLUE): Complete$(RESET)"

main:
	gcc -Wall -Wextra -Werror main.c $(INCLUDES) $(NAME)

re: fclean all

.PHONY: clean fclean re