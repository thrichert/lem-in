/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_way_calc_next_noeud.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <apopinea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 16:50:38 by apopinea          #+#    #+#             */
/*   Updated: 2018/04/26 19:15:05 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lemin.h"

void	lem_way_calc_next_noeud(t_lem_env *e, int id, t_way *way)
{
	int		i;
	t_way	*tmp_way;

	i = 0;
	while (i < e->rooms[id].n_next)
	{
		if (lem_already_here(way, e->rooms[id].id_next[i]))
		{
			if (!(tmp_way = (t_way*)ft_memalloc(sizeof(t_way))))
				lem_close(2, e, "s", "ERROR!\n\terror malloc 3\n");
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
			lem_calcul_way(e, e->rooms[id].id_next[i], tmp_way);
		}
		++i;
	}
	lem_sup_way(way);
}
