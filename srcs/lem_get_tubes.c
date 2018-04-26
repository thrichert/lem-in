/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_get_tubes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <apopinea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 18:53:38 by apopinea          #+#    #+#             */
/*   Updated: 2018/04/26 18:53:59 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lemin.h"

void	lem_get_tubes(t_lem_env *e, char *s)
{
	int	a;
	int	b;

	while (s)
	{
		if (ft_strsplit_buf2(s, '-') != 2)
		{
			free(s);
			return ;
		}
		a = lem_search_room_name(e, s);
		b = lem_search_room_name(e, s + id_next_str(s, 0));
		free(s);
		if (a == -1 || b == -1)
			return ;
		lem_save_tubes(e, a, b);
		lem_save_tubes(e, b, a);
		s = lem_trash_line(&(e->buf));
	}
}
