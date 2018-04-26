/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_recoup_way2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <apopinea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 18:45:11 by apopinea          #+#    #+#             */
/*   Updated: 2018/04/26 18:45:42 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lemin.h"

char	lem_recoup_way2(t_way *way1, t_way *way2)
{
	int	i;
	int	j;
	int k;
	int l;

	i = 1;
	k = way1->n_noeuds - 1;
	l = way2->n_noeuds - 1;
	while (i < k)
	{
		j = 1;
		while (j < l)
		{
			if (way1->noeuds[i] == way2->noeuds[j])
			{
				return (FAIL);
			}
			++j;
		}
		++i;
	}
	return (SUCCESS);
}
