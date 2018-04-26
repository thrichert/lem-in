/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_calcul_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <apopinea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 18:47:53 by apopinea          #+#    #+#             */
/*   Updated: 2018/04/26 18:48:05 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lemin.h"

int		lem_calcul_size(t_lem_env *e, int id1, int id2)
{
	int	a;
	int	b;

	a = e->rooms[id2].x - e->rooms[id1].x;
	if (a < 0)
		a = -a;
	b = e->rooms[id2].y - e->rooms[id1].y;
	if (b < 0)
		return (a - b);
	return (a + b);
}
