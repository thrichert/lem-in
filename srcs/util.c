/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trichert <trichert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 19:04:43 by trichert          #+#    #+#             */
/*   Updated: 2018/03/22 16:06:23 by trichert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		++i;
	}
	free(tab);
	tab = NULL;
}

t_room	*give_me_room_with_name(t_env *e, char *name)
{
	t_lst	*tmp;
	t_room	*r;

	tmp = e->room;
	while (tmp)
	{
		r = (t_room*)tmp->data;
		if (ft_strcmp(r->name, name) == 0)
			return (r);
		tmp = tmp->next;
	}
	return (NULL);
}

t_room	*give_me_room_with_id(t_env *e, int i)
{
	t_lst	*tmp;
	t_room	*r;

	tmp = e->room;
	while (tmp)
	{
		r = (t_room*)tmp->data;
		if (r->id == i)
			return (r);
		tmp = tmp->next;
	}
	return (NULL);
}

t_way	*give_me_shorter_way(t_env *e)
{
	t_way	*w;
	int		min;

	min = INT_MAX;
	w = e->ways;
	while (w)
	{
		if ((w->v == SUCCESS) && (w->l < min))
			min = w->l;
		w = w->next;
	}
	w = e->ways;
	while (w)
	{
		if ((w->v == SUCCESS) && w->l == min)
			return (w);
		w = w->next;
	}
	return (NULL);
}
