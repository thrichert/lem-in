/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_stdin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trichert <trichert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 11:29:19 by trichert          #+#    #+#             */
/*   Updated: 2018/03/12 20:53:16 by trichert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static char	basic_check(t_env *e)
{
	if (!e->lines)
	{
		e->status |= ERROR;
		ft_error_v(2, "RFLs", FFL, "ERROR!\n\tNo input provided\n");
		close_lemin(e, ERROR_CLOSE);
	}
	if (e->lines == '\0')
		return (FAIL);
	return (SUCCESS);
}

static char	get_line(t_env *e)
{
	int i;

	i = 0;
	if (!basic_check(e))
		return (FAIL);
	while (e->lines[e->id + i])
	{
		if (e->lines[e->id + i] == '\n')
		{
			if (e->cline)
				free(e->cline);
			e->cline = ft_strndup(e->lines + e->id, i);
			e->id += i + 1;
			return (SUCCESS);
		}
		++i;
	}
	if (e->cline)
		free(e->cline);
	e->cline = ft_strndup(e->lines + e->id, i);
	e->id += i;
	if (ft_strcmp(e->cline, "\n") == 0 || ft_strcmp(e->cline, "\0") == 0)
		return (FAIL);
	return (SUCCESS);
}

char		gnl(t_env *e)
{
	int		ret;
	char	*tmp;

	if (e->cline)
	{
		free(e->cline);
		e->cline = NULL;
	}
	if ((ret = read(0, e->buf, BUF)) > 0)
	{
		e->buf[ret] = '\0';
		if (e->lines == NULL)
		{
			if (!(e->lines = ft_strdup(e->buf)))
				return (ft_error_c(2, "RFLsn", FFL, E_MLC));
		}
		else
		{
			tmp = ft_strjoin(e->lines, e->buf);
			free(e->lines);
			e->lines = tmp;
		}
	}
	return (get_line(e));
}
