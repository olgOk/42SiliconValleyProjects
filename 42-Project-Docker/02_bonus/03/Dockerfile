# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/26 21:36:47 by vokrut            #+#    #+#              #
#    Updated: 2019/06/26 21:37:54 by vokrut           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian

MAINTAINER vokrut "vokrut@student.42.us.org"

RUN apt-get update && apt-get install -y cowsay fortune lolcat

ENTRYPOINT /usr/games/fortune | /usr/games/cowsay | /usr/games/lolcat