# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/24 12:07:04 by vokrut            #+#    #+#              #
#    Updated: 2019/06/24 12:16:30 by vokrut           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM ubuntu:16.04

MAINTAINER vokrut "vokrut@student.42.us.org"

RUN apt-get update && \
    apt-get upgrade -y && \
    apt-get install -y ca-certificates openssh-server wget postfix

RUN wget https://packages.gitlab.com/install/repositories/gitlab/gitlab-ce/script.deb.sh && chmod 777 script.deb.sh && ./script.deb.sh && apt-get install -y gitlab-ce

RUN apt update && apt install -y tzdata && \
  apt-get clean && rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*

EXPOSE 443 80 22

ENTRYPOINT (/opt/gitlab/embedded/bin/runsvdir-start &) && gitlab-ctl reconfigure && tail -f /dev/null