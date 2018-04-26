/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_move_ant.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <apopinea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 16:43:28 by apopinea          #+#    #+#             */
/*   Updated: 2018/04/26 16:43:42 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lemin.h"

void	lem_move_ant(t_lem_env *e, int i)
{
	int	k;
	int	j;

	k = e->ways[e->ants[i].way]->noeuds[e->ants[i].id_noeud + 1];
	j = e->ants[i].room;
	if (e->rooms[k].state == 0 || k == e->id_room_e)
	{
		e->rooms[j].state -= 1;
		e->ants[i].room = k;
		e->rooms[k].state += 1;
		++(e->ants[i].id_noeud);
		ft_printf("L%d-%s ", i, e->rooms[k].name);
	}
}
