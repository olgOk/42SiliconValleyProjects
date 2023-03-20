# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    script.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vokrut <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/01 19:42:55 by vokrut            #+#    #+#              #
#    Updated: 2019/03/01 22:35:34 by vokrut           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

if [[ $EUID > 0 ]]; then
	echo "Please run as root/sudo"
	exit 1
else
	#Install OpenSSH server repository
	apt-get install openssh-server -y
	#Making copy of the original repository
	cp /etc/ssh/sshd_config /etc/ssh/sshd_config_copy
	#Replacing port by default, which is Port22, with the new one
	sed -i 's/^.*Port 22/Port 6969/g' /etc/ssh/sshd_config
	#Restart the SSH service with the new port number
	/etc/init.d/ssh restart	
fi
