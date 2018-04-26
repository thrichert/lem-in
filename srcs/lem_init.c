/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <apopinea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 18:50:13 by apopinea          #+#    #+#             */
/*   Updated: 2018/04/26 18:51:14 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lemin.h"

void	lem_init(t_lem_env *e)
{
	char *s;

	ft_bzero(e, sizeof(t_lem_env));
	e->id_room_s = -1;
	e->id_room_e = -1;
	lem_get_nb_fourmis(e);
	lem_get_tubes(e, lem_get_rooms(e));
	while(gnll(0, &s))
	{
		if (s != NULL)
		{
			trash_save(&(e->buf), s);
			free(s);
		}
	}
	e->n_util_way = e->rooms[e->id_room_s].n_next;
	if (e->n_util_way > e->rooms[e->id_room_e].n_next)
		e->n_util_way = e->rooms[e->id_room_e].n_next;
}
