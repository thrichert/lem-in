/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_state_machine.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trichert <trichert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 18:34:19 by trichert          #+#    #+#             */
/*   Updated: 2018/03/13 00:01:24 by trichert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static char	check_line_get_cmd(t_env *e)
{
	if (e->stat_line == L_IS_BASE_S)
	{
		if (!get_room(e, R_IS_START))
		{
			e->status |= ERROR;
			return (FAIL);
		}
		e->status |= HAS_START;
	}
	else if (e->stat_line == L_IS_BASE_E)
	{
		if (!get_room(e, R_IS_END))
		{
			e->status |= ERROR;
			return (FAIL);
		}
		e->status |= HAS_END;
	}
	e->status &= ~GET_CMD;
	e->stat_line = 0;
	return (SUCCESS);
}

static char	check_line_is_cmd(t_env *e)
{
	e->status |= GET_CMD;
	if (!(e->status & HAS_ANTS))
	{
		e->status |= ERROR;
		e->stat_line = L_IS_WRONG;
		return (ft_error_c(2, "s", "ERROR!\n\tNo ants provided\n"));
	}
	else if (e->cline[2] == 's' && !(e->status & HAS_START))
		e->stat_line = L_IS_BASE_S;
	else if (e->cline[2] == 'e' && !(e->status & HAS_END))
		e->stat_line = L_IS_BASE_E;
	return (SUCCESS);
}

static char	buff_overflw_checkin(char *s)
{
	int		i;
	char	*tab;

	i = 0;
	tab = "2147483647";
	while (i < 10)
	{
		if (s[i] > tab[i])
		{
			return (ft_error_c(2, "s",
			"ERROR!\n\tnunmber ants should be ]0 - 2147483647]\n"));
		}
		++i;
	}
	return (SUCCESS);
}

static void	check_line_get_ants(t_env *e)
{
	e->stat_line = L_IS_NANTS;
	if (ft_strlen(e->cline) > 9 && buff_overflw_checkin(e->cline))
	{
		e->stat_line = L_IS_WRONG;
		e->status |= ERROR;
		return ;
	}
	if (ft_strchr_i(e->cline, '-') != -1 ||
		(e->n_ants = ft_atoi(e->cline)) < 0)
	{
		e->stat_line = L_IS_WRONG;
		e->status |= ERROR;
		return (ft_error_v(2, "s",
		"ERROR!\n\tNegative number of ants provided\n"));
	}
	e->status |= HAS_ANTS;
	e->status |= GET_ROOMS;
}

char		check_line(t_env *e)
{
	if (!e->cline)
		return (ft_error_c(2, "s", "ERROR!\n\tNo line provided!\n"));
	if (e->cline[0] == '#' && e->cline[1] != '#')
		return (SUCCESS);
	else if ((ft_strncmp(e->cline, "##start", e->lline) == 0 ||
				ft_strncmp(e->cline, "##end", e->lline) == 0))
		return (check_line_is_cmd(e));
	else if (ft_strncmp(e->cline, "##", 1) == 0)
		return (SUCCESS);
	else if (e->status & GET_CMD)
		return (check_line_get_cmd(e));
	else if (!(e->status & HAS_ANTS))
		check_line_get_ants(e);
	else if (e->status & GET_ROOMS)
	{
		if (!get_room(e, R_IS_ROOM))
			return (FAIL);
	}
	else if (e->status & GET_TUBS && !get_tubs(e))
		return (FAIL);
	return (SUCCESS);
}
