/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_search_way.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <apopinea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 16:45:29 by apopinea          #+#    #+#             */
/*   Updated: 2018/04/26 16:45:44 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lemin.h"

int		lem_search_way(t_lem_env *e)
{
	int i;
	int	k;

	i = 0;
	k = -1;
	while (i < e->n_ways)
	{
		if (e->rooms[e->ways[i]->noeuds[1]].state == 0 ||
			e->ways[i]->noeuds[1] == e->id_room_e)
		{
			if (k == -1)
				k = i;
			else
			{
				if (e->ways[i]->n_noeuds < e->ways[k]->n_noeuds)
					k = i;
				else if (e->ways[i]->n_noeuds == e->ways[k]->n_noeuds &&
					e->ways[i]->size < e->ways[k]->size)
					k = i;
			}
		}
		++i;
	}
	return (lem_search_way2(e, k));
}
