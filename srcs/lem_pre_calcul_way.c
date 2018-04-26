/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_pre_calcul_way.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <apopinea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 16:08:33 by apopinea          #+#    #+#             */
/*   Updated: 2018/04/26 19:15:59 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lemin.h"

void	lem_pre_calcul_way(t_lem_env *e)
{
	t_way	*way;

	if (!(way = (t_way*)ft_memalloc(sizeof(t_way))))
		lem_close(2, e, "s", "ERROR!\n\terror malloc 4\n");
	lem_calcul_way(e, e->id_room_s, way);
	if (e->n_ways < 1)
		lem_close(2, e, "s", "ERROR!\n\tno way\n");
	ft_printf("%s\n", e->buf);
}
