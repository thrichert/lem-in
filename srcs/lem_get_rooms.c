/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_get_rooms.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <apopinea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 18:57:19 by apopinea          #+#    #+#             */
/*   Updated: 2018/04/26 18:57:36 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lemin.h"

char	*lem_get_rooms(t_lem_env *e)
{
	char	*s;
	int		nb_split;
	t_lst	*lst;

	lst = NULL;
	while((s = lem_trash_line(&(e->buf))))
	{
		ft_strtrim_back(s);
		if (s[0] == '#')
			lem_get_cmd(e, s, &lst);
		else
		{
			nb_split = ft_strsplit_buf2(s, ' ');
			if (nb_split == 3)
				lem_get_normal_room(e, s, &lst);
			else
				break ;
		}
	}
	lem_save_rooms(e, lst);
	if (e->id_room_e == -1 || e->id_room_s == -1)
		lem_close(2, e, "s", "ERROR!\n\tbad ending or starting room\n");
	return (s);
}
