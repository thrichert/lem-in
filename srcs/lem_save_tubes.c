/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_save_tubes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <apopinea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 18:55:05 by apopinea          #+#    #+#             */
/*   Updated: 2018/04/26 18:55:21 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lemin.h"

void	lem_save_tubes(t_lem_env *e, int a, int b)
{
	int	i;

	i = 0;
	while (i < e->rooms[a].n_next)
	{
		if (e->rooms[a].id_next[i] == b)
			return ;
		++i;
	}
	i = sizeof(int) * e->rooms[a].n_next;
	e->rooms[a].id_next = ft_rememalloc2(e->rooms[a].id_next, i,
		i + sizeof(int));
	e->rooms[a].id_next[e->rooms[a].n_next] = b;
	++(e->rooms[a].n_next);
}
