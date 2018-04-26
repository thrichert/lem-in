/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_calcul_way.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <apopinea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 16:11:38 by apopinea          #+#    #+#             */
/*   Updated: 2018/04/26 16:12:05 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lemin.h"

void	lem_calcul_way(t_lem_env *e, int id, t_way *way)
{
	if (id == e->id_room_e)
	{
		return (lem_way_find(e, id, way));
	}
	lem_way_calc_next_noeud(e, id, way);
}
