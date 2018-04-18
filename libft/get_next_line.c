/* *********************************************i**************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 21:50:47 by linh              #+#    #+#             */
/*   Updated: 2018/01/26 15:38:25 by linh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define IS_VALID(x) if (!x) return (-1);
#include <stdio.h>

static char	*locate_newline(char *str)
{
	int		i;
	char	*new;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			break ;
		i++;
	}
	new = (char*)malloc(sizeof(char) * (i + 1));
	new[i] = '\0';
	i = i - 1;
	while (i >= 0)
	{
		new[i] = str[i];
		i--;
	}
	return (new);
}

static int	cal_newline(char *str)
{
	int count;
	int i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			count++;
		i++;
	}
	return (count);
}

int			get_next_line(const int fd, char **line)
{
	VARS;
	if (fd < 0 || fd > 4999 || !line)
		return (-1);
	if (!fd_s[fd])
		fd_s[fd] = ft_strnew(0);
	while (!ft_strchr(fd_s[fd], '\n') && (ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret < 0)
			return (-1);
		buf[ret] = '\0';
		while (++j < ret)
		{
			if (buf[j] == '\n')
			{
				tmp = fd_s[fd];
				fd_s[fd] = ft_strjoin(tmp, buf);
				free(tmp);
				*line = locate_newline(fd_s[fd]);
				tmp = fd_s[fd];
				fd_s[fd] = ft_strdup((ft_strchr(fd_s[fd], '\n') + 1));
				free(tmp);
				return (1);
			}
		}
		tmp = fd_s[fd];
		fd_s[fd] = ft_strjoin(tmp, buf);
		free(tmp);
	}
	if (cal_newline(fd_s[fd]) > 0 && (*line = locate_newline(fd_s[fd])))
	{
		tmp = fd_s[fd];
		fd_s[fd] = ft_strdup((ft_strchr(fd_s[fd], '\n') + 1));
		free(tmp);
		return (1);
	}
	if (ft_strlen(fd_s[fd]) > 0 && (*line = locate_newline(fd_s[fd])))
	{
//		*line = locate_newline(fd_s[fd]);
		free(fd_s[fd]);
		fd_s[fd] = ft_strnew(0);
		return (1);
	}
	ft_memdel((void**)&fd_s[fd]);
	return (0);
}
