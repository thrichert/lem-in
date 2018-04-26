/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_pre_launch_ants.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <apopinea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 16:34:10 by apopinea          #+#    #+#             */
/*   Updated: 2018/04/26 16:37:50 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lemin.h"

void	lem_pre_launch_ants(t_lem_env *e)
{
	int i;

	if (!(e->ants = (t_ant*)malloc(sizeof(t_ant) * e->n_ants)))
		lem_close(2, e, "s", "ERROR!\n\terror malloc 5\n");
	ft_printf("\n", e->n_ants);
	i = 0;
	while (i < e->n_ants)
	{
		e->ants[i].room = e->id_room_s;
		e->ants[i].way = -1;
		e->ants[i].id_noeud = 0;
		++i;
	}
	lem_clear_room(e);
	e->rooms[e->id_room_s].state = e->n_ants;
	e->id_best_way = lem_search_way(e);
	e->n_s_ants = e->n_ants;
	lem_launch_ants(e);
}
