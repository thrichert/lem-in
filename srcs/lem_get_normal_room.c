/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_get_normal_room.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <apopinea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 19:02:06 by apopinea          #+#    #+#             */
/*   Updated: 2018/04/26 19:02:22 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lemin.h"

void	lem_get_normal_room(t_lem_env *e, char *s, t_lst **lst)
{
	t_room	*r;
	int		i;

	lem_verif_room_name(e, s, *lst);
	if (!(r = (t_room*)ft_memalloc(sizeof(t_room))))
		lem_close(2, e, "ssn", "ERROR!\n\t", E_MLC);
	r->name = s;
	i = id_next_str(s, 0);
	r->x = ft_atoi(s + i);
	i = id_next_str(s, i);
	r->y = ft_atoi(s + i);
	ft_lst_push_front(lst, ft_lstnew_nm(r, sizeof(t_room)));
	++(e->n_rooms);
}
