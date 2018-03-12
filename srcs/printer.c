/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trichert <trichert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 20:28:25 by trichert          #+#    #+#             */
/*   Updated: 2018/03/12 20:53:42 by trichert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	print_at_start(t_env *e, t_room *prev, t_room *t)
{
	if (prev->id == END_ID && t->id != START_ID)
	{
		--(e->ants_at_s);
		++(e->ants_at_e);
		prev->idf = e->n_ants - e->ants_at_s;
		ft_printf("L%d-%s ", t->idf, prev->name);
	}
	else if (prev->id == END_ID && t->id == START_ID)
	{
		--(e->ants_at_s);
		++(e->ants_at_e);
		ft_printf("L%d-%s ", e->n_ants - e->ants_at_s, prev->name);
	}
	else if (prev->stats & R_IS_FREE)
	{
		--(e->ants_at_s);
		prev->idf = e->n_ants - e->ants_at_s;
		ft_printf("L%d-%s ", prev->idf, prev->name);
		prev->stats |= R_IS_OCPY;
		prev->stats &= ~R_IS_FREE;
	}
}

static void	print_otherwise(t_env *e, t_room *prev, t_room *t)
{
	if (prev->id == END_ID)
	{
		ft_printf("L%d-%s ", t->idf, prev->name);
		t->stats &= ~R_IS_OCPY;
		t->stats |= R_IS_FREE;
		++(e->ants_at_e);
	}
	else if (prev->stats & R_IS_FREE)
	{
		prev->idf = t->idf;
		prev->stats |= R_IS_OCPY;
		prev->stats &= ~R_IS_FREE;
		t->stats &= ~R_IS_OCPY;
		t->stats |= R_IS_FREE;
		ft_printf("L%d-%s ", prev->idf, prev->name);
	}
}

void		render_way(t_env *e, t_way *w)
{
	t_room	*t;
	t_lst	*tmp;
	t_room	*prev;

	tmp = w->r;
	e->ants_at_s = e->n_ants;
	while (e->ants_at_e < e->n_ants)
	{
		++(e->tot_steps);
		tmp = w->r;
		while (tmp)
		{
			t = (t_room*)tmp->data;
			if (t->id == START_ID && e->ants_at_s > 0)
			{
				print_at_start(e, prev, t);
				break ;
			}
			else if (t->stats & R_IS_OCPY)
				print_otherwise(e, prev, t);
			prev = t;
			tmp = tmp->next;
		}
		ft_printf("\n");
	}
}
