/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trichert <trichert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 17:17:45 by trichert          #+#    #+#             */
/*   Updated: 2018/03/12 17:21:10 by trichert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_way *give_me_shorter_way(t_env *e)
{
	t_way	*w;
	int		min;

	min = INT_MAX;
	w = e->ways;
	while (w)
	{
		if (w->v && w->l < min)
			min = w->l;
		w = w->next;
	}
	w = e->ways;
	while (w)
	{
		if (w->v && w->l == min)
			return (w);
		w = w->next;
	}
	return (NULL);
}

char check_solvability(t_env *e, t_room *cur)
{
	t_lst *tmp;
	t_room *r;
	t_way *tmp_w;

	cur->stats |= R_IS_FREE;
	(e->ways)->l += 1;
	(e->ways)->r = ft_lst_push_front_r((e->ways)->r, ft_lstnew_nm(cur, sizeof(t_room*)));
	if (!cur)
		return (ft_error_c(2, "s", "cur = null..."));
	else
	{
		tmp = cur->neighbours;
		if (!tmp)
			return (ft_error_c(2, "s", "no neighbours..."));
		while (tmp)
		{

			r = (t_room*)tmp->data;
			if (r->id == END_ID)
			{
				(e->ways)->r = ft_lst_push_front_r((e->ways)->r, ft_lstnew_nm(r, sizeof(t_room*)));
				e->ways->v = SUCCESS;
				++(e->n_w);
				tmp_w = (t_way*)ft_memdup(e->ways, sizeof(t_way));
				ft_bzero(e->ways, sizeof(t_way));
				(e->ways)->next = tmp_w;
				e->ways->l = 1;
				e->ways->r = ft_lst_push_front_r((e->ways)->r, ft_lstnew_nm(give_me_room_with_id(e, START_ID), sizeof(t_room*)));
				return (SUCCESS);
			}
			else if (r->stats & R_IS_FREE || !check_solvability(e, r))
				tmp = tmp->next;
		}
		e->ways->v = FAIL;
	}


	if (e->n_w > 0)
		return (SUCCESS);
	return (FAIL);
}

char is_not_in_lst(t_room **r)
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
			if (rp->id == r[(i - 1)*(i - 1)]->id)
				return (FAIL);
			l1 = l1->next;
		}
		++i;
	}
	return (SUCCESS);
}

char get_tubs(t_env *e)
{
	char **tab;
	int len;
	t_room *r[2];

	len = 0;
	tab = ft_strsplit(e->cline, '-');
	while (tab[len])
		++len;
	if (len < 2)
	{
		e->status |= ERROR;
		//free tab
		len = 0;
		while (tab[len])
		{
			free(tab[len]);
			tab[len] = NULL;
			++len;
		}
		free(tab);
		tab = NULL;
		return (ft_error_c(2, "s", "ERROR!\n\tBad link format!\n"));
	}
	if (!(r[0] = give_me_room_with_name(e, tab[0])) || !(r[1] = give_me_room_with_name(e, tab[1])))
	{
		e->status |= ERROR;
		//free tab
		len = 0;
		while (tab[len])
		{
			free(tab[len]);
			tab[len] = NULL;
			++len;
		}
		free(tab);
		tab = NULL;
		return (ft_error_c(2, "s", "ERROR!\n\tBad room names in link!\n"));
	}
	if (is_not_in_lst(r))
	{
		r[0]->neighbours = ft_lst_push_front_r((r[0]->neighbours), ft_lstnew_nm(r[1], sizeof(t_room)));
		r[1]->neighbours = ft_lst_push_front_r((r[1]->neighbours), ft_lstnew_nm(r[0], sizeof(t_room)));
	}
	else
	{
		e->status |= ERROR;
		//free tab
		len = 0;
		while (tab[len])
		{
			free(tab[len]);
			tab[len] = NULL;
			++len;
		}
		free(tab);
		tab = NULL;
		return (ft_error_c(2, "s", "ERROR!\n\tNeed only one link between rooms...\n"));
	}
	++(e->n_l);
	//free tab
	len = 0;
	while (tab[len])
	{
		free(tab[len]);
		tab[len] = NULL;
		++len;
	}
	free(tab);
	tab = NULL;
	return (SUCCESS);
}

char check_line(t_env *e)
{
	if (!e->cline)
	{
		e->stat_line = L_IS_WRONG;
		e->status |= ERROR;
		return (ft_error_c(2, "s", "ERROR!\n\tNo line provided!\n"));
	}
	if (e->cline[0] == '#' && e->cline[1] != '#')
	{
		// print comment
		// e->stat_line = L_IS_COMMENT;
		return (SUCCESS);
	}
	else if (e->status & GET_CMD)
	{


		//	get command
		if (e->stat_line == L_IS_BASE_S)
		{	// get start base
			if (!get_room(e, R_IS_START))
			{
				e->status |= ERROR;
				return (FAIL);
			}
			e->status |= HAS_START;

		}
		else if (e->stat_line == L_IS_BASE_E)
		{	// get end base
			if (!get_room(e, R_IS_END))
			{
				e->status |= ERROR;
				return (FAIL);
			}
			e->status |= HAS_END;
		}
		e->status &= ~GET_CMD;
		e->stat_line = 0;
		return (SUCCESS);

	}
	else if (e->cline[0] == '#' && e->cline[1] == '#')
	{

		// is command
		e->status |= GET_CMD;
		if (!(e->status & HAS_ANTS))
		{
			e->status |= ERROR;
			e->stat_line = L_IS_WRONG;
			return (ft_error_c(2, "s", "ERROR!\n\tNo ants provided\n"));
		}
		else if (ft_strcmp(e->cline, "##start") == 0 && !(e->status & HAS_START))
		{
			e->stat_line = L_IS_BASE_S;
			return (SUCCESS);
		}
		else if (ft_strcmp(e->cline, "##end") == 0 && !(e->status & HAS_END))
		{
			e->stat_line = L_IS_BASE_E;
			return (SUCCESS);
		}
		else
		{
			e->status |= ERROR;
			e->stat_line = L_IS_WRONG;
			return (ft_error_c(2, "s", "ERROR!\n\tIllegal command\n"));
		}

	}
	else if (!(e->status & HAS_ANTS))
	{
		//get number of ants
		e->stat_line = L_IS_NANTS;

		if (ft_strlen(e->cline) > 9)
		{
			int i;
			char *tab;
			i = 0;
			tab = "2147483647";
			while (i < 10)
			{
				if (e->cline[i] > tab[i])
					return (ft_error_c(2, "s", "ERROR!\n\tnunmber ants should be ]0 - 2147483647]\n"));
				++i;
			}
			e->stat_line = L_IS_WRONG;
			e->status |= ERROR;
			return (ft_error_c(2, "s", "WARNING!\n"));
		}
		if (ft_strchr_i(e->cline, '-') != -1 || (e->n_ants = ft_atoi(e->cline)) < 0)
		{
			e->stat_line = L_IS_WRONG;
			e->status |= ERROR;
			return (ft_error_c(2, "s", "ERROR!\n\tNegative number of ants provided\n"));
		}
		e->status |= HAS_ANTS;
		e->status |= GET_ROOMS;

	}
	else if (e->status & GET_ROOMS)
	{
		if (!get_room(e, R_IS_ROOM))
		{
			e->status |= ERROR;
			return (FAIL);
		}
	}
	else if (e->status & GET_TUBS)
	{
		if (!get_tubs(e))
		{
			e->status |= ERROR;
			return (FAIL);
		}
	}
	return (SUCCESS);
}


void test(void)
{
	t_env e;
	t_way *w;


	t_room *t;
	// t_room *t2;
	t_lst *tmp;
	// t_lst *tmp2;

	ft_bzero(&e, sizeof(t_env));
	e.n_r = 2;
	while (gnl(&e))
	{
		if (!check_line(&e))
			close_lemin(&e, ERROR_CLOSE);

	}

	if (e.n_l == 0)
	{
		ft_error_v(2, "s", "ERROR!\n\tMissing links between room!\n");
		close_lemin(&e, ERROR_CLOSE);
	}



	if (e.status & GET_TUBS)
	{

		e.status &= ~GET_TUBS;
		e.ways = (t_way*)ft_memalloc(sizeof(t_way));
		e.ways->next = NULL;
		if (!check_solvability(&e, give_me_room_with_id(&e, START_ID)))
		{

			ft_error_v(2, "s", "ERROR!\n\tNo path between Start <-> End found!\n");
			close_lemin(&e, ERROR_CLOSE);
		}
		e.status |= SOLVING;

	}

	if (e.status & SOLVING)
	{
		w = give_me_shorter_way(&e);
		tmp = w->r;
		e.ants_at_s = e.n_ants;
		ft_printf("TOT ants : %d\n", e.n_ants);
		t_room *prev;
		while (e.ants_at_e < e.n_ants)
		{
			++(e.tot_steps);
			tmp = w->r;
			while (tmp)
			{
				t = (t_room*)tmp->data;
				if (t->id == START_ID && e.ants_at_s > 0)
				{
					// ft_printf("ants left : %d\n", e.ants_at_s);
					if (prev->id == END_ID)
					{
						--(e.ants_at_s);
						++(e.ants_at_e);
						prev->idf = e.n_ants - e.ants_at_s;
						ft_printf("L%d-%s ", prev->idf, prev->name);
						// ft_printf("> ants reach end !<\n");
						// ft_printf("> %d <\n", e.ants_at_e);
					}
					else if (prev->stats & R_IS_FREE)
					{
						--(e.ants_at_s);
						prev->idf = e.n_ants - e.ants_at_s;
						ft_printf("L%d-%s ", prev->idf, prev->name);
						prev->stats |= R_IS_OCPY;
						prev->stats &= ~R_IS_FREE;
					}
					break;
				}
				else if (t->stats & R_IS_OCPY)
				{
					if(prev->id == END_ID)
					{
						ft_printf("L%d-%s ", t->idf, prev->name);
						// ft_printf("> ants reach end !<\n");
						t->stats &= ~R_IS_OCPY;
						t->stats |= R_IS_FREE;
						++(e.ants_at_e);
						// ft_printf("> %d <\n", e.ants_at_e);
					}
					else if (prev->stats & R_IS_FREE)
					{
						ft_printf("L%d-%s ", prev->idf, prev->name);
						prev->stats |= R_IS_OCPY;
						prev->stats &= ~R_IS_FREE;
						t->stats &= ~R_IS_OCPY;
						t->stats |= R_IS_FREE;
					}
				}
				prev = t;
				tmp = tmp->next;

			}
			ft_printf("\n");
		}
		ft_printf("problem solved in > %d < steps\n", e.tot_steps);


	}
	/////////

	// tmp = e.room;
	// while (tmp)
	// {
	// 	t = (t_room*)(tmp->data);
	// 	ft_printf(" ROOM : %s id : %d [%d , %d] : %d\n", (char*)t->name, t->id, t->pos.x, t->pos.y, t->stats);
	// 	tmp2 = t->neighbours;
	// 	while (tmp2)
	// 	{
	// 		t2 = (t_room*)tmp2->data;
	// 			ft_printf("\tlinkto : %s\n", t2->name);
	// 		tmp2 = tmp2->next;
	// 	}
	// 	tmp = tmp->next;
	// }



	// int i;
	// // t_way *w;
	// w = e.ways;
	// i = 0;
	// while (w)
	// {
	// 	if (w->v)
	// 	{
	// 		ft_printf("----- route : %d as l : %d\n", i, w->l);
	// 		tmp = (t_lst*)w->r;

	// 		while (tmp)
	// 		{
	// 			if (tmp->data)
	// 			{
	// 				t = (t_room*)tmp->data;
	// 				 ft_printf("ROOM : %s id: %d\n", t->name, t->id);
	// 			}
	// 			tmp = tmp->next;
	// 		}
	// 	}
	// 	++i;
	// 	w = w->next;
	// }

	// w = give_me_shorter_way(&e);
	// while (e.ants_at_e != e.n_ants)
	// {

	// }


	close_lemin(&e, NORMAL_CLOSE);
}

int main(void)
{

	test();

	return (0);
}