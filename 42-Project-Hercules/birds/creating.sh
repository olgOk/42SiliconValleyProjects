# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    creating.sh                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/04 16:30:09 by vokrut            #+#    #+#              #
#    Updated: 2019/04/05 19:13:26 by vokrut           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

RED='\033[0;31m'
NC='\033[0m'

if [ "$#" -ne 2 ]
then
    echo "${RED}=>${NC}Provide directory path and or project name"
else
    DIREC=$1
    PROJECT=$2
    mkdir $DIREC/src
    mkdir $DIREC/incl
    mkdir $DIREC/resources

    cd $DIREC
    echo "${RED}=>${NC}Creating author file... "
    echo $USER>>author
    echo "${RED}=>${NC}Creating Makefile..."
    MAKEFILE=Makefile
    echo "# **************************************************************************** #" >> $MAKEFILE
    echo "#                                                                              #" >> $MAKEFILE
    echo "#                                                         :::      ::::::::    #" >> $MAKEFILE
    echo "#    $(printf "%-50s %s" $NAME):+:      :+:    :+:    #" >> $MAKEFILE
    echo "#                                                     +:+ +:+         +:+      #" >> $MAKEFILE
    echo "#    By: $(printf "%-41s %s " "$USER <$USER@student.42.us.org>" )+#+  +:+       +#+         #" >> $MAKEFILE
    echo "#                                                 +#+#+#+#+#+   +#+            #" >> $MAKEFILE
    echo "#    Created: $( echo "$(date +'%Y/%m/%d %T')" ) by $(printf "%-17s %s" $USER)#+#    #+#              #" >> $MAKEFILE
    echo "#    Updated: $( echo "$(date +'%Y/%m/%d %T')" ) by $(printf "%-16s %s" $USER)###   ########.fr        #" >> $MAKEFILE
    echo "#                                                                              #" >> $MAKEFILE
    echo "# **************************************************************************** #" >> $MAKEFILE
	echo "">>$MAKEFILE
    echo "NAME = $( echo "$PROJECT" )">>$MAKEFILE
    echo "">>$MAKEFILE
    echo "CC = gcc">>$MAKEFILE
    echo "">>$MAKEFILE
    echo "CFLAGS = -Wall -Wextra -Werror" >> $MAKEFILE
    echo "">>$MAKEFILE
    echo "">>$MAKEFILE
    echo "SRC = ./src main.c">>$MAKEFILE
    echo "">>$MAKEFILE
    echo "INCL = ./incl">>$MAKEFILE
    echo "">>$MAKEFILE
    echo "LIBFT = src/libft/libft.a">>$MAKEFILE
    echo "">>$MAKEFILE
    echo 'all: $(NAME)'>>$MAKEFILE
    echo "">>$MAKEFILE
    echo "\$(NAME):">>$MAKEFILE
    echo "  make -C libft">>$MAKEFILE
    echo "  \$(CC) \$(CFLAGS) \$(SRC) \$(LIBFT) -o \$(NAME)">>$MAKEFILE
    echo "">>$MAKEFILE
    echo "clean:">>$MAKEFILE
    echo "  make -C libft clean">>$MAKEFILE
    echo "">>$MAKEFILE
    echo "fclean: clean">>$MAKEFILE
    echo "  /bin/rm -f \$(NAME)">>$MAKEFILE
    echo "  make -C libft fclean">>$MAKEFILE
    echo "">>$MAKEFILE
    echo "re: fclean all">>$MAKEFILE
    echo "${RED}=>${NC}Creating main function..."
    cd src
    touch main.c
    MAINFILE=main.c
    echo "/* ************************************************************************** */">>$MAINFILE
    echo "/*                                                                            */">>$MAINFILE
    echo "/*                                                        :::      ::::::::   */">>$MAINFILE
    echo "/*   $(printf "%-50s %s" main.c):+:      :+:    :+:   */" >> $MAINFILE
    echo "/*                                                    +:+ +:+         +:+     */">>$MAINFILE
    echo "/*   By: $(printf "%-41s %s " "$USER <$USER@student.42.us.org>" )+#+  +:+       +#+        */">>$MAINFILE
    echo "/*                                                +#+#+#+#+#+   +#+           */">>$MAINFILE
    echo "/*   Created: $( echo "$(date +'%Y/%m/%d %T')" ) by $(printf "%-17s %s" $USER)#+#    #+#             */">>$MAINFILE
    echo "/*   Updated: $( echo "$(date +'%Y/%m/%d %T')" ) by $(printf "%-16s %s" $USER)###   ########.fr       */">>$MAINFILE
    echo "/*                                                                            */">>$MAINFILE
    echo "/* ************************************************************************** */">>$MAINFILE
    echo "">>$MAINFILE
    echo "int       main()">>$MAINFILE
    echo "{">>$MAINFILE
    echo "  return (0);">>$MAINFILE
    echo "}">>$MAINFILE
    echo ""
    echo "${RED}=>${NC}Copying libft to the project ..."
    mkdir libft;
    echo "${RED}=>${NC}Provide libft path >>"
    read LIBFTPATH
    cp -R ~/$LIBFTPATH/  libft;
fi
    exit 0