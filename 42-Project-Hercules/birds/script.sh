# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    script.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/04 11:59:30 by vokrut            #+#    #+#              #
#    Updated: 2019/04/05 19:13:30 by vokrut           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

RED='\033[0;31m'
NC='\033[0m'

gitignore()
{
    IGNPATH=$DIR/.gitignore
    echo "${RED}=>${NC}Generating gitignore ..."
    echo "*.DS_Store" >> $IGNPATH
    echo "a.out" >> $IGNPATH
    echo "a.out" >> $IGNPATH
    echo "._*" >> $IGNPATH
    echo ".vscode" >> $IGNPATH
}

# Help menu
help()
{
    echo "${RED}Escape basic routine work using create-project automation"
    echo "${RED}usage: ./script.sh [ -h -c ]"
    echo "${RED}-h${NC}                      Display help menu"
    echo "${RED}-c${NC}                      Create a new project"
}

createProject()
{
    while [ "$projectName" == "" ]
    do
        echo "${RED}=>${NC}Project name: ${RED}>>${NC} "
        read projectName
    done

    DIR=./$projectName
    
    while true;
    do
        if [ -d $DIR ]
        then
            echo "${RED}=>${NC}Directory already exists. Try with other name"
            exit 0
        else
            mkdir $DIR
            PROJECTPATH=$(pwd)
            echo "${RED}=>${NC}Directory $DIR has been successfully created. Path: $PROJECTPATH$DIR"
            break ;
        fi
    done
    PROJECTPATH=$(pwd)
    echo ""
    echo "${RED}=>${NC}Please select programming language"
    echo "${RED}=>${NC}c         for C programming language"
    echo "${RED}=>${NC}exit      to abort the program"
    read LANG

    case $LANG in
    c)
    ./creating.sh $DIR $projectName
    ;;
    exit)
    exit 0
    ;;
    *)
    echo "${RED}=>${NC}Unsupported action! Try again"
    exit 0
    esac
}


if [[ "$1" == "-h" && $# == 1 ]]
then
     help
elif [[ "$1" == "-c" && $# == 1 ]]
then
    createProject
    gitignore
    echo "${RED}=>${NC}Project $projectName has been successfully created!"
else 
    echo "${RED}=>${NC}program usage [-h -c]"
fi
exit 0