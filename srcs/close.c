/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trichert <trichert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 15:28:24 by trichert          #+#    #+#             */
/*   Updated: 2018/03/22 17:48:39 by trichert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	free_room(t_env *e)
{
	t_room	*r;
	t_lst	*l;
	t_lst	*l3;

	l = e->room;
	while (l)
	{
		l3 = l->next;
		r = (t_room*)l->data;
		if (r->name)
		{
			free(r->name);
			r->name = NULL;
		}
		ft_lstdel_nodata(&(r->neighbours));
		r->neighbours = NULL;
		free(r);
		free(l);
		l = l3;
	}
	e->room = NULL;
}

static void	free_ways(t_env *e)
{
	t_way	*tmp_w;
	t_way	*tmp_w1;

	tmp_w = e->ways;
	while (tmp_w)
	{
		tmp_w1 = tmp_w->next;
		if (tmp_w->r)
			ft_lstdel_nodata(&(tmp_w->r));
		tmp_w->r = NULL;
		free(tmp_w);
		tmp_w = tmp_w1;
	}
	e->ways = NULL;
}

int			close_lemin(t_env *e, char opt)
{
	if (e->lines)
	{
		free(e->lines);
		e->lines = NULL;
	}
	if (e->cline)
	{
		free(e->cline);
		e->cline = NULL;
	}
	if (e->ways)
		free_ways(e);
	if (e->room)
		free_room(e);
	if (opt == NORMAL_CLOSE)
		return (SUCCESS);
	else if (opt == ERROR_CLOSE)
		exit(0);
	return (FAIL);
}
