/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_already_here.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <apopinea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 18:46:54 by apopinea          #+#    #+#             */
/*   Updated: 2018/04/26 19:14:45 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lemin.h"

char	lem_already_here(t_way *way, int id)
{
	int	i;

	i = 0;
	while (i < way->n_noeuds)
	{
		if (id == way->noeuds[i])
			return (FAIL);
		++i;
	}
	return (SUCCESS);

}
