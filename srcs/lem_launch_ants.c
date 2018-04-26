/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_launch_ants.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <apopinea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 16:36:23 by apopinea          #+#    #+#             */
/*   Updated: 2018/04/26 16:36:42 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lemin.h"

void	lem_launch_ants(t_lem_env *e)
{
	int i;

	while (e->rooms[e->id_room_e].state < e->n_ants)
	{
		i = 0;
		while (i < e->n_ants)
		{
			if (e->ants[i].room != e->id_room_e)
			{
				if (e->ants[i].way == -1)
					e->ants[i].way = lem_search_way(e);
				if (e->ants[i].way != -1)
					lem_move_ant(e, i);
			}
			++i;
		}
		e->n_s_ants = e->rooms[e->id_room_s].state;
		ft_printf("\n");
	}
}
