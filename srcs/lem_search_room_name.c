/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_search_room_name.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <apopinea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 18:56:01 by apopinea          #+#    #+#             */
/*   Updated: 2018/04/26 18:56:25 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lemin.h"

int		lem_search_room_name(t_lem_env *e, char *s)
{
	int	i;

	i = 0;
	while(i < e->n_rooms)
	{
		if (ft_strcmp_np(s, e->rooms[i].name) == 0)
			return (i);
		++i;
	}
	return (-1);
}
