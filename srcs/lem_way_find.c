/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_way_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <apopinea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 16:52:09 by apopinea          #+#    #+#             */
/*   Updated: 2018/04/26 16:55:46 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lemin.h"

void	lem_way_find(t_lem_env *e, int id, t_way *way)
{
	t_way	*tmp_way;

	if (!(tmp_way = (t_way*)malloc(sizeof(t_way))))
		lem_close(2, e, "s", "ERROR!\n\terror malloc 4\n");
	tmp_way->noeuds = int_dup_plus(way->noeuds, way->n_noeuds,
		way->n_noeuds + 1);
	tmp_way->noeuds[way->n_noeuds] = id;
	tmp_way->n_noeuds = way->n_noeuds + 1;
	if (way->n_noeuds == 0)
		tmp_way->size = way->size + lem_calcul_size(e, id,
			e->id_room_s);
	else
		tmp_way->size = way->size + lem_calcul_size(e, id,
			tmp_way->noeuds[way->n_noeuds - 1]);
	lem_save_way(e, tmp_way);
	lem_sup_way(way);
}
