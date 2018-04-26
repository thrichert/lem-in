/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_print_rooms.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <apopinea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 18:52:14 by apopinea          #+#    #+#             */
/*   Updated: 2018/04/26 18:52:31 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lemin.h"

void	lem_print_rooms(t_lem_env *e)
{
	int	i;
	int	j;

	i = 0;
	while (i < e->n_rooms)
	{
		ft_printf("\n%s %d %d id = %d ", e->rooms[i].name, e->rooms[i].x,
			e->rooms[i].y, i);
		if (i == e->id_room_s)
			ft_printf(" : start");
		else if (i == e->id_room_e)
			ft_printf(" : end");
		j = 0;
		while (j < e->rooms[i].n_next)
		{
			ft_printf("\n\t%d", e->rooms[i].id_next[j]);
			++j;
		}
		ft_printf("\n");
		++i;
	}
	ft_printf("\n%s\n", e->buf);
}
