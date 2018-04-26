/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_search_way2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <apopinea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 16:46:23 by apopinea          #+#    #+#             */
/*   Updated: 2018/04/26 16:46:42 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lemin.h"

int		lem_search_way2(t_lem_env *e, int k)
{
	if (k != e->id_best_way && k != -1)
	{
		if (!(e->n_s_ants >
		(e->ways[k]->n_noeuds - e->ways[e->id_best_way]->n_noeuds + 1)))
			return (-1);
	}
	return (k);
}
