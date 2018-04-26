/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_save_way.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <apopinea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 18:37:09 by apopinea          #+#    #+#             */
/*   Updated: 2018/04/26 19:16:47 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lemin.h"

void	lem_save_way(t_lem_env *e, t_way *way)
{
	int 	k;
	t_way	*tmp_way;

	k = lem_recoup_way(e, way);
	if (k >= 0)
	{
		tmp_way = e->ways[k];
		e->ways[k] = way;
		way = tmp_way;
		lem_sup_way(way);
		return ;
	}
	if (k == -1)
	{
		if (e->n_ways < e->n_util_way)
			return (lem_save_way_add(e, way));
		else
			lem_save_way_sort(e, way);
	}
	lem_sup_way(way);
}
