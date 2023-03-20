# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/21 12:58:58 by vokrut            #+#    #+#              #
#    Updated: 2019/06/24 15:30:28 by vokrut           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:latest

MAINTAINER vokrut "vokrut@student.42.us.org"

ENV TS3SERVER_LICENSE=accept

WORKDIR /home/teamspeak

EXPOSE 9987/udp 10011 30033

RUN apt-get update && \
    apt-get upgrade -y && \
    apt-get install -y wget bzip2 && \
    wget http://dl.4players.de/ts/releases/3.0.13.4/teamspeak3-server_linux_amd64-3.0.13.4.tar.bz2 && \
    tar -xvf teamspeak3-server_linux_amd64-3.0.13.4.tar.bz2

WORKDIR teamspeak3-server_linux_amd64

ENTRYPOINT sh ts3server_minimal_runscript.sh