/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trichert <trichert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 15:28:24 by trichert          #+#    #+#             */
/*   Updated: 2018/03/12 12:14:55 by trichert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int close_lemin(t_env *e, char opt)
{
	t_way *tmp_w;
	t_way *tmp_w1;
	t_room *r;
	t_lst *l;
	t_lst *l3;

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
	ft_printf("boom1\n");

	if (e->ways)
	{
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
	ft_printf("boom2\n");

	if (e->room)
	{
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
	ft_printf("boom3\n");

	if (opt == NORMAL_CLOSE)
	{
		ft_error_v(2, "s", "lem-in stopped and exit correctly\n");
		return (SUCCESS);
	}
	else if (opt == ERROR_CLOSE)
	{
		ft_error_d(2, "s", "lem-in exit after an error occur\n");
		exit(0);
	}
	return (FAIL);
}

