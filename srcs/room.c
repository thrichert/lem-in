/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trichert <trichert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 12:00:54 by trichert          #+#    #+#             */
/*   Updated: 2018/03/12 20:08:43 by trichert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_room	*malloc_room(char **tab, int stats, int len)
{
	char	*tmp;
	int		i;
	t_room	*r;

	if (!(r = (t_room*)ft_memalloc(sizeof(t_room))))
		return (ft_error_n(2, "RFLsn", E_MLC));
	r->stats = stats;
	r->pos.x = ft_atoi(tab[len - 2]);
	r->pos.y = ft_atoi(tab[len - 1]);
	i = 0;
	while (i < len - 2)
	{
		if (!r->name)
			r->name = ft_strdup(tab[i]);
		else
		{
			tmp = ft_strjoin_3(r->name, " ", tab[i]);
			if (r->name)
				free(r->name);
			r->name = tmp;
		}
		++i;
	}
	return (r);
}

static char		create_room(t_env *e, char **tab, int stats, int len)
{
	t_room *r;

	if (!(r = malloc_room(tab, stats, len)))
		return (FAIL);
	if (give_me_room_with_name(e, r->name))
	{
		free_tab(tab);
		return (ft_error_c(2, "s", "ERROR!\n\tDuplicate room name\n"));
	}
	free_tab(tab);
	if (r->name[0] == 'L' || r->name[0] == '#')
		return (ft_error_c(2, "s", "ERROR!\n\tBad room name\n"));
	if (r->stats == R_IS_START)
		r->id = START_ID;
	else if (r->stats == R_IS_END)
		r->id = END_ID;
	else
	{
		r->id = e->n_r;
		(e->n_r)++;
	}
	e->room = ft_lst_push_front_r((e->room), ft_lstnew_nm(r, sizeof(t_room)));
	return (SUCCESS);
}

static char		start_get_tubs(t_env *e, char **tab)
{
	free_tab(tab);
	if (!give_me_room_with_id(e, START_ID) || !give_me_room_with_id(e, END_ID))
	{
		e->status |= ERROR;
		return (ft_error_c(2, "s", "ERROR!\n\tRoom missing!\n"));
	}
	if (ft_strchr_i(e->cline, '-') != -1)
	{
		e->stat_line = L_IS_TUNEL;
		e->status &= ~GET_ROOMS;
		e->status |= GET_TUBS;
		if (!get_tubs(e))
		{
			e->status |= ERROR;
			return (FAIL);
		}
		return (SUCCESS);
	}
	else
	{
		e->status |= ERROR;
		return (ft_error_c(2, "s", "ERROR!\n\tBad room format!\n"));
	}
}

char			get_room(t_env *e, int stats)
{
	char	**tab;
	int		len;

	len = 0;
	tab = ft_strsplit(e->cline, ' ');
	while (tab[len])
		++len;
	if (len < 3 && e->stat_line != L_IS_BASE_E && e->stat_line != L_IS_BASE_S)
		return (start_get_tubs(e, tab));
	else if (len >= 3)
	{
		if (!create_room(e, tab, stats, len))
		{
			e->status |= ERROR;
			return (FAIL);
		}
		return (SUCCESS);
	}
	else
	{
		e->status |= ERROR;
		free_tab(tab);
		return (ft_error_c(2, "s", "ERROR!\n\tIllegal command\n"));
	}
}
