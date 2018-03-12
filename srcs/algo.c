/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trichert <trichert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 19:22:43 by trichert          #+#    #+#             */
/*   Updated: 2018/03/12 20:26:02 by trichert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static char	rinit_way(t_env *e, t_room *r)
{
	t_way *tmp_w;

	e->status |= HAS_PATH;
	++(e->n_w);
	(e->ways)->r = ft_lst_push_front_r((e->ways)->r,
			ft_lstnew_nm(r, sizeof(t_room*)));
	e->ways->v = SUCCESS;
	tmp_w = (t_way*)ft_memdup(e->ways, sizeof(t_way));
	ft_bzero(e->ways, sizeof(t_way));
	(e->ways)->next = tmp_w;
	e->ways->l = 1;
	e->ways->r = ft_lst_push_front_r((e->ways)->r,
			ft_lstnew_nm(give_me_room_with_id(e, START_ID), sizeof(t_room*)));
	return (SUCCESS);
}

char		check_solvability(t_env *e, t_room *cur)
{
	t_lst	*tmp;
	t_room	*r;

	cur->stats |= R_IS_FREE;
	(e->ways)->l += 1;
	(e->ways)->r = ft_lst_push_front_r((e->ways)->r,
			ft_lstnew_nm(cur, sizeof(t_room*)));
	tmp = cur->neighbours;
	while (tmp)
	{
		r = (t_room*)tmp->data;
		if (r->id == END_ID)
			return (rinit_way(e, r));
		else if (r->stats & R_IS_FREE || !check_solvability(e, r))
			tmp = tmp->next;
	}
	e->ways->v = FAIL;
	if (e->n_w > 0)
		return (SUCCESS);
	return (FAIL);
}
