/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trichert <trichert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 17:17:45 by trichert          #+#    #+#             */
/*   Updated: 2018/03/12 00:55:48 by trichert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"


t_room	*give_me_room_with_name(t_env *e, char *name)
{
	t_lst *tmp;
	t_room *r;

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
	t_lst *tmp;
	t_room *r;

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
			if (r->id == 1)
			{
				(e->ways)->r = ft_lst_push_front_r((e->ways)->r, ft_lstnew_nm(r, sizeof(t_room*)));
				e->ways->v = SUCCESS;
				++(e->n_w);
				tmp_w = (t_way*)ft_memdup(e->ways, sizeof(t_way));
				// ft_lstdel_nodata(&(e->ways->r));
				ft_bzero(e->ways, sizeof(t_way));
				(e->ways)->next = tmp_w;



				// t_way *w;
				// w = e->ways;
				// tmp = w->r;
				// tmp = tmp->next;

				// ft_printf("data : %s\n", ((t_room*)tmp->data)->name);




				e->ways->l = 1;
				e->ways->r = ft_lst_push_front_r((e->ways)->r, ft_lstnew_nm(give_me_room_with_id(e, 0), sizeof(t_room*)));
				return (SUCCESS);
			}
			else if (r->stats & R_IS_FREE)
			{
				tmp = tmp->next;
			}
			else if  (!check_solvability(e, r))
			{
				tmp = tmp->next;
			}

		}
		e->ways->v = FAIL;
	}


	if (e->n_w > 0)
		return (SUCCESS);
	return FAIL;
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
	r[0]->neighbours = ft_lst_push_front_r((r[0]->neighbours), ft_lstnew_nm(r[1], sizeof(t_room)));
	r[1]->neighbours = ft_lst_push_front_r((r[1]->neighbours), ft_lstnew_nm(r[0], sizeof(t_room)));
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

char get_room(t_env *e, int stats)
{
	char **tab;
	int len, i;
	t_room *r;
	char *tmp;


	len = 0;
	tab = ft_strsplit(e->cline, ' ');
	while (tab[len])
		++len;
	if (len < 3 && e->stat_line != L_IS_BASE_E && e->stat_line != L_IS_BASE_S)
	{
		// free strsplit(' ')
		i = 0;
		while (tab[i])
		{
			free(tab[i]);
			tab[i] = NULL;
			++i;
		}
		free(tab);
		tab = NULL;
		// check start / end room:

		if (!give_me_room_with_id(e, 0) || !give_me_room_with_id(e, 1))
			return (ft_error_c(2, "s", "ERROR!\n\tRoom missing!\n"));

		len = ft_strchr_i(e->cline, '-');
		if (len != -1)
		{
			e->stat_line = L_IS_TUNEL;
			e->status &= ~GET_ROOMS;
			e->status |= GET_TUBS;



			if (!get_tubs(e))
				return (FAIL);


			return (SUCCESS);
		}
		else
			return (ft_error_c(2, "s", "ERROR!\n\tBad room format!\n"));
	}
	else if (len >= 3)
	{
		if (!(r = (t_room*)ft_memalloc(sizeof(t_room))))
			return (ft_error_c(2, "RFLsn", E_MLC));

		r->stats = stats;
		r->pos.x = ft_atoi(tab[len - 2]);
		r->pos.y = ft_atoi(tab[len - 1]);

		i = 0;
		while (i < len - 2)
		{
			if (!r->name)
				r->name = ft_strdup(tab[i]);
			else
			{
				tmp = ft_strjoin_3(r->name, " ", tab[i]);
				if (r->name)
					free(r->name);
				r->name = tmp;
			}
			++i;
		}


		// free strsplit(' ')
		i = 0;
		while (tab[i])
		{
			free(tab[i]);
			tab[i] = NULL;
			++i;
		}
		free(tab);
		tab = NULL;


		if (r->name[0] == 'L' || r->name[0] == '#')
		{
			return (ft_error_c(2, "s",  "ERROR!\n\tBad room name\n"));
		}
		if (r->stats == R_IS_START)
			r->id = 0;
		else if (r->stats == R_IS_END)
			r->id = 1;
		else
		{
			r->id = e->n_r;
			(e->n_r)++;
		}
		e->room = ft_lst_push_front_r((e->room), ft_lstnew_nm(r, sizeof(t_room)));

		return (SUCCESS);
	}
	else
	{
		// free strsplit(' ')
		i = 0;
		while (tab[i])
		{
			free(tab[i]);
			tab[i] = NULL;
			++i;
		}
		free(tab);
		tab = NULL;
		return (ft_error_c(2, "s", "ERROR!\n\tIllegal command\n"));
	}
}

char	check_line(t_env *e)
{
	if (!e->cline)
	{
		e->stat_line = L_IS_WRONG;
		return (ft_error_c(2, "s", "ERROR!\n\tNo line provided!\n"));
	}
	if (e->status & GET_CMD)
	{


		//	get command
		if (e->stat_line == L_IS_BASE_S)
		{	// get start base
			if (!get_room(e, R_IS_START))
				return (FAIL);
			e->status |= HAS_START;

		}
		else if (e->stat_line == L_IS_BASE_E)
		{	// get end base
			if (!get_room(e, R_IS_END))
				return (FAIL);
			e->status |= HAS_END;
		}
		e->status &= ~GET_CMD;
		e->stat_line = 0;
		return (SUCCESS);

	}
	if (e->cline[0] == '#' && e->cline[1] == '#')
	{

		// is command
		e->status |= GET_CMD;
		if (!(e->status & HAS_ANTS))
		{
			e->status |= ERROR;
			e->stat_line = L_IS_WRONG;
			return (ft_error_c(2, "s", "ERROR!\n\tNo ants provided\n"));
		}
		else if (ft_strcmp(e->cline, "##start") == 0)
		{
			e->stat_line = L_IS_BASE_S;
			return (SUCCESS);
		}
		else if (ft_strcmp(e->cline, "##end") == 0)
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
	else if (e->cline[0] == '#' && e->cline[1] != '#')
	{
		// print comment
		e->stat_line = L_IS_COMMENT;
	}
	else if (!(e->status & HAS_ANTS))
	{
		//get number of ants
		e->stat_line = L_IS_NANTS;
		if ((e->n_ants = ft_atoi(e->cline)) < 0)
		{
			e->stat_line = L_IS_WRONG;
			e->status |= ERROR;
			return (ft_error_c(2, "s", "ERROR!\n\tNegative number of ants provided"));
		}
		e->status |= HAS_ANTS;
		e->status |= GET_ROOMS;

	}
	else if (e->status & GET_ROOMS)
	{
		if (!get_room(e, R_IS_ROOM))
			return (FAIL);
	}
	else if (e->status & GET_TUBS)
	{
		if (!get_tubs(e))
			return (FAIL);
	}
	return (SUCCESS);
}

void test(void)
{
	t_env e;

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
		if (!check_solvability(&e, give_me_room_with_id(&e, 0)))
		{
			ft_error_v(2, "s", "ERROR!\n\tNo path between Start <-> End found!\n");
			close_lemin(&e, ERROR_CLOSE);
		}
		e.status |= SOLVING;
	}



	/////////

	// t_room *t;
	// t_room *t2;
	// t_lst *tmp;
	// t_lst *tmp2;
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

	// ft_printf("data : %s\n", ((t_room*)(e.ways->r->data))->name);
	// t_way *w;
	// w = e.ways;
	// tmp = w->r;
	// tmp = tmp->next;

	// ft_printf("data : %s\n", ((t_room*)tmp->data)->name);

	int i;
	t_way *w;
	w = e.ways;
	i = 0;
	while (w)
	{
		if (w->v)
		{
			ft_printf("----- route : %d as l : %d\n", i, w->l);
			tmp = (t_lst*)w->r;
			// ft_printf("tmp : %p  data : %s\n", tmp, ((t_room*)(tmp->data))->name);

			while (tmp)
			{
				if (tmp->data)
				{
					t = (t_room*)tmp->data;
					// ft_printf("ROOM : %s\n", t->name);
				}
				tmp = tmp->next;
			}
		}
		++i;
		w = w->next;
	}
	close_lemin(&e, NORMAL_CLOSE);
}

int main(void)
{

	test();
	while (1);


	return (0);
}