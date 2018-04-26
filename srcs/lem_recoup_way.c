/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_recoup_way.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <apopinea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 18:43:43 by apopinea          #+#    #+#             */
/*   Updated: 2018/04/26 19:16:29 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lemin.h"

char	lem_recoup_way(t_lem_env *e, t_way *way)
{
	int	i;
	int j;
	int k;

	if (way->n_noeuds < 1)
		return (FAIL);
	j = 0;
	i = -1;
	k = 0;
	while (++i < e->n_ways)
	{
		if (!lem_recoup_way2(e->ways[i], way))
		{
			++j;
			k = i;
		}
	}
	if (j == 0)
		return (-1);
	if (j == 1 && ((way->n_noeuds < e->ways[k]->n_noeuds) ||
			(way->n_noeuds == e->ways[k]->n_noeuds &&
			way->size < e->ways[k]->size)))
		return (k);
	return (-2);
}
