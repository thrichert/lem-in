/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trichert <trichert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 19:22:43 by trichert          #+#    #+#             */
/*   Updated: 2018/03/22 19:33:53 by trichert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static char	rinit_way(t_env *e, t_room *r, t_room *cur)
{
	e->status |= HAS_PATH;
	e->ways->v = SUCCESS;
	++(e->n_w);
	(e->ways)->r = ft_lst_push_front_r((e->ways)->r,
		ft_lstnew_nm(r, sizeof(t_room*)));
	(e->ways)->r = ft_lst_push_front_r((e->ways)->r,
		ft_lstnew_nm(cur, sizeof(t_room*)));
	return (SUCCESS);
}

char		check_solvability(t_env *e, t_room *cur)
{
	t_lst	*tmp;
	t_room	*r;

	cur->stats |= R_IS_FREE;
	(e->ways)->l += 1;
	tmp = cur->neighbours;
	while (tmp)
	{
		r = (t_room*)tmp->data;
		if (r->id == START_ID)
			return (rinit_way(e, r, cur));
		else if (r->stats & R_IS_FREE || !check_solvability(e, r))
		{
			tmp = tmp->next;
			continue;
		}
		(e->ways)->r = ft_lst_push_front_r((e->ways)->r,
			ft_lstnew_nm(cur, sizeof(t_room*)));
		return (SUCCESS);
	}
	return (FAIL);
}
