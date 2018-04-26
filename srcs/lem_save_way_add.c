/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_save_way_add.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <apopinea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 18:39:54 by apopinea          #+#    #+#             */
/*   Updated: 2018/04/26 18:40:21 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lemin.h"

void	lem_save_way_add(t_lem_env *e, t_way *way)
{
	int	i;

	i = sizeof(t_way*) * e->n_ways;
	if (!(e->ways = ft_rememalloc2(e->ways, i, i + sizeof(t_way*))))
		lem_close(2, e, "s", "ERROR!\n\terror malloc 2\n");
	e->ways[e->n_ways] = way;
	++(e->n_ways);
}
