/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tubs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trichert <trichert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 19:29:26 by trichert          #+#    #+#             */
/*   Updated: 2018/03/12 20:54:32 by trichert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static char	is_not_in_lst(t_room **r)
{
	t_lst	*l1;
	t_room	*rp;
	int		i;

	i = 0;
	while (i < 2)
	{
		l1 = r[i]->neighbours;
		while (l1)
		{
			rp = (t_room*)l1->data;
			if (rp->id == r[(i - 1) * (i - 1)]->id)
				return (FAIL);
			l1 = l1->next;
		}
		++i;
	}
	return (SUCCESS);
}

static char	add_room_neighbours(t_env *e, t_room **r, char **tab)
{
	if (is_not_in_lst(r))
	{
		r[0]->neighbours = ft_lst_push_front_r((r[0]->neighbours),
			ft_lstnew_nm(r[1], sizeof(t_room)));
		r[1]->neighbours = ft_lst_push_front_r((r[1]->neighbours),
			ft_lstnew_nm(r[0], sizeof(t_room)));
		return (SUCCESS);
	}
	else
	{
		e->status |= ERROR;
		free_tab(tab);
		return (ft_error_c(2, "s",
			"ERROR!\n\tNeed only one link between rooms...\n"));
	}
}

char		get_tubs(t_env *e)
{
	char	**tab;
	int		len;
	t_room	*r[2];

	len = 0;
	tab = ft_strsplit(e->cline, '-');
	while (tab[len])
		++len;
	if (len < 2)
	{
		free_tab(tab);
		return (ft_error_c(2, "s", "ERROR!\n\tBad link format!\n"));
	}
	if (!(r[0] = give_me_room_with_name(e, tab[0])) ||
		!(r[1] = give_me_room_with_name(e, tab[1])))
	{
		free_tab(tab);
		return (ft_error_c(2, "s", "ERROR!\n\tBad room names in link!\n"));
	}
	if (!add_room_neighbours(e, r, tab))
		return (FAIL);
	++(e->n_l);
	free_tab(tab);
	return (SUCCESS);
}
