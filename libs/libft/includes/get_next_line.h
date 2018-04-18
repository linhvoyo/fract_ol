/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 21:52:31 by linh              #+#    #+#             */
/*   Updated: 2018/02/23 10:23:58 by linh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# define VARS char buf[BUFF_SIZE + 1];int ret;int j=-1;static char *fd_s[4999]; char *tmp;

int get_next_line(const int fd, char **line);

#endif
