/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_get_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <apopinea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 18:59:54 by apopinea          #+#    #+#             */
/*   Updated: 2018/04/26 19:01:16 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lemin.h"

void		lem_get_cmd(t_lem_env *e, char *s, t_lst **lst)
{
	if (ft_strcmp_np("##start", s) == 0)
	{
		if (e->id_room_s != -1)
			lem_close(2, e, "s", "ERROR!\n\tCMD ##start already exist\n");
		e->id_room_s = e->n_rooms;
		free(s);
		s = lem_trash_line(&(e->buf));
		if (ft_strsplit_buf2(s, ' ') != 3)
			lem_close(2, e, "s", "ERROR!\n\tthe line next CMD ##start, bad\n");
		lem_get_normal_room(e, s, lst);
		return ;
	}
	if (ft_strcmp_np("##end", s) == 0)
	{
		if (e->id_room_e != -1)
			lem_close(2, e, "s", "ERROR!\n\tCMD ##end already exist\n");
		e->id_room_e = e->n_rooms;
		free(s);
		s = lem_trash_line(&(e->buf));
		if (ft_strsplit_buf2(s, ' ') != 3)
			lem_close(2, e, "s", "ERROR!\n\tthe line next CMD ##end, bad\n");
		lem_get_normal_room(e, s, lst);
		return ;
	}
	lem_close(2, e, "s", "ERROR!\n\tCommande start or end for rooms : error\n");
}
