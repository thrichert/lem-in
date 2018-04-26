/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_save_rooms.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <apopinea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 18:58:36 by apopinea          #+#    #+#             */
/*   Updated: 2018/04/26 18:58:54 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lemin.h"

void	lem_save_rooms(t_lem_env *e, t_lst *lst)
{
	int		i;
	t_lst	*elem;

	if (!(e->rooms = (t_room*)ft_memalloc(sizeof(t_room) * e->n_rooms)))
		lem_close(2, e, "s", "ERROR!\n\terror malloc 1\n");
	i = e->n_rooms;
	while(i)
	{
		--i;
		e->rooms[i].name = ((t_room*)(lst->data))->name;
		e->rooms[i].x = ((t_room*)(lst->data))->x;
		e->rooms[i].y = ((t_room*)(lst->data))->y;
		elem = lst;
		lst = lst->next;
		free(elem);
	}
}
