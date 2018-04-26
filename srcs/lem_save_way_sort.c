/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_save_way_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <apopinea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 18:25:21 by apopinea          #+#    #+#             */
/*   Updated: 2018/04/26 18:25:45 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lemin.h"

void	lem_save_way_sort(t_lem_env *e, t_way *way)
{
	int		i;
	t_way	*tmp_way;

	i = 0;
	while (i < e->n_ways)
	{
		if ((way->n_noeuds < e->ways[i]->n_noeuds) ||
			(way->n_noeuds == e->ways[i]->n_noeuds &&
			way->size < e->ways[i]->size))
		{
			tmp_way = e->ways[i];
			e->ways[i] = way;
			way = tmp_way;
			i = 0;
		}
		else
			++i;
	}
}
