/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 17:19:54 by vokrut            #+#    #+#             */
/*   Updated: 2019/03/12 12:10:40 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_line(const int fd, char **str, char **line)
{
	char	*tmp;
	size_t	len;

	len = 0;
	while (str[fd][len] != '\n' && str[fd][len] != '\0')
		len++;
	if (str[fd][len] == '\n')
	{
		*line = ft_strsub(str[fd], 0, len);
		tmp = ft_strdup(str[fd] + len + 1);
		free(str[fd]);
		str[fd] = tmp;
	}
	else if (str[fd][len] == '\0')
	{
		*line = ft_strdup(str[fd]);
		ft_strdel(&str[fd]);
	}
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	static char		*str[OPEN_MAX];
	char			buf[BUFF_SIZE + 1];
	char			*str_tmp;
	ssize_t			n;

	if (!line || BUFF_SIZE < 0 || fd < 0 || fd > OPEN_MAX)
		return (-1);
	while ((n = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[n] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strnew(1);
		str_tmp = ft_strjoin(str[fd], buf);
		free(str[fd]);
		str[fd] = str_tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (n < 0)
		return (-1);
	if (n == 0 && (!str[fd] || str[fd][0] == '\0'))
		return (0);
	return (ft_line(fd, str, line));
}
