/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_sup_way.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <apopinea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 16:58:13 by apopinea          #+#    #+#             */
/*   Updated: 2018/04/26 16:58:31 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lemin.h"

void	lem_sup_way(t_way *way)
{
	if (!way)
		return ;
	if (way->noeuds)
	{
		free(way->noeuds);
		way->noeuds = NULL;
		way->n_noeuds = 0;
		way->size = 0;
	}
	free(way);
}
