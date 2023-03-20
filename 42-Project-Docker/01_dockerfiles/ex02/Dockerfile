# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/24 11:34:29 by vokrut            #+#    #+#              #
#    Updated: 2019/06/24 11:37:17 by vokrut           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM ruby

MAINTAINER vokrut "vokrut@student.42.us.org"

RUN apt-get update -y && apt-get install -y build-essential libpq-dev nodejs sqlite3

ONBUILD COPY app /opt/app
ONBUILD WORKDIR /opt/app

ONBUILD EXPOSE 3000
ONBUILD RUN bundle install
ONBUILD RUN rake db:migrate
ONBUILD RUN rake db:seed