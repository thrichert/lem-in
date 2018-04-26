/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <apopinea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 14:37:46 by apopinea          #+#    #+#             */
/*   Updated: 2018/04/24 14:42:56 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_lmain.h"

int		gnl_n_in_buf(char **buf, char **line, int i, int l)
{
	char *tmp;

	while (i < l)
	{
		if ((*buf)[i] == '\n')
		{
			if (i == (l - 1))
			{
				(*buf)[i] = '\0';
				*line = *buf;
				*buf = NULL;
				return (l + 1);
			}
			else
			{
				*line = ft_strndup(*buf, i);
				tmp = ft_strndup(*buf + i + 1, l - i - 1);
				free(*buf);
				*buf = tmp;
				return (i + 1);
			}
		}
		++i;
	}
	return ( -1);
}

int		gnl_no_n_in_buf(char **buf, char **line, int fd, int l)
{
	int		ret;
	int		i;

	while ((ret = read(fd, *buf + l, BUFF_SIZE_GNL)))
	{
		i = l;
		l += ret;
		if ((i = gnl_n_in_buf(buf, line, i, l)) > 0)
			return (i);
		if (!(*buf = ft_rememalloc(*buf, l, l + BUFF_SIZE_GNL + 1)))
			return (-1);
		(*buf)[l + BUFF_SIZE_GNL] = '\0';
	}
	if (l > ret)
	{
		if ((i = gnl_n_in_buf(buf, line, 0, l)) > 0)
			return (i);
	}
	(*buf)[l] = '\0';
	*line = *buf;
	*buf = NULL;
	return (l);
}

int		gnll(int fd, char **line)
{
	static char	*buf = NULL;
	int			j;
	int			l;

	if (fd < 0 || !line || BUFF_SIZE_GNL < 1)
		return (-1);
	*line = NULL;
	if (buf)
	{
		l = ft_strlen_np(buf);
		if ((j = gnl_n_in_buf(&buf, line, 0, l)) > 0)
			return (j);
		if (!(buf = ft_rememalloc(buf, l, l + BUFF_SIZE_GNL + 1)))
			return (-1);
		buf[l + BUFF_SIZE_GNL] = '\0';
		return (gnl_no_n_in_buf(&buf, line, fd, l));
	}
	if (!(buf = (char*)malloc(BUFF_SIZE_GNL + 1)))
		return (-1);
	(buf)[BUFF_SIZE_GNL] = '\0';
	return (gnl_no_n_in_buf(&buf, line, fd, 0));
}
