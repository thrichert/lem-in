/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trichert <trichert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 17:17:45 by trichert          #+#    #+#             */
/*   Updated: 2018/03/09 20:02:09 by trichert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

char get_room(t_env *e)
{
	char **tab;
	int len, i;
	t_room *r;
	char *tmp;

	if (!(r = (t_room*)malloc(sizeof(t_room))))
		return (ft_error_c(2, "RFLsn", E_MLC));
	r->name = NULL;
	len = 0;
	tab = ft_strsplit(e->cline, ' ');
	while (tab[len])
		++len;
	r->pos.x = ft_atoi(tab[len - 1]);
	r->pos.y = ft_atoi(tab[len]);
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
	e->room = ft_lst_push_front_r((e->room), ft_lstnew_nm(r, sizeof(t_room)));
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

char	check_line(t_env *e)
{
	if (!e->cline)
	{
		e->stat_line = L_IS_WRONG;
		return (ft_error_c(2, "s", "No line provided!\n"));
	}
	if (e->status & GET_CMD)
	{
		//	get command
		if (e->stat_line == L_IS_BASE_S)
		{	// get start base
			ft_putendl("GET START BASE");
			get_room(e);
		}
		else if (e->stat_line == L_IS_BASE_E)
		{	// get end base
			ft_putendl("GET END BASE");
			get_room(e);
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
			return (ft_error_c(2, "s", "No ants provided\n"));
		}
		else if (ft_strcmp(e->cline, "##start") == 0)
		{
			e->stat_line = L_IS_BASE_S;
			e->status |= HAS_START; // sup apres verif
			return (SUCCESS);
		}
		else if (ft_strcmp(e->cline, "##end") == 0)
		{
			e->stat_line = L_IS_BASE_E;
			e->status |= HAS_END; // sup apres verif
			return (SUCCESS);
		}
		else
		{
			e->status |= ERROR;
			e->stat_line = L_IS_WRONG;
			return (ft_error_c(2, "s", "Illegal command\n"));
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
			return (ft_error_c(2, "s", "Negative number of ants provided"));
		}
		e->status |= HAS_ANTS;
		e->status |= GET_ROOMS;
	}
	else if (e->status & GET_ROOMS)
	{

	}
	return (SUCCESS);
}

char	get_line(t_env *e)
{
	int i;

	i = 0;
	if (!e->lines)
		return (ft_error_c(2, "RFLs", FFL, "no input provided\n"));
	while (e->lines[e->id + i])
	{
		if (e->lines[e->id + i] == '\n')
		{
			e->cline = ft_strndup(e->lines + e->id, i);
			e->id += i + 1;
			return (SUCCESS);
		}
		++i;
	}
	return (FAIL);
}

char	ft_gnl(t_env *e)
{
	int ret;
	char *tmp;

	while ((ret = read(0, e->buf, BUF)) > 0)
	{
		e->buf[ret] = '\0';
		if (e->lines == NULL)
		{
			if (!(e->lines = ft_strdup(e->buf)))
				return (ft_error_c(2, "RFLsn", FFL, E_MLC));
		}
		else
		{
			tmp = ft_strjoin(e->lines, e->buf);
			if (e->lines)
			{
				free(e->lines);
				e->lines = NULL;
			}
			e->lines = tmp;
		}
		if (!get_line(e))
		 	return (FAIL);
		return (SUCCESS);
	}
	if (!get_line(e))
		return (FAIL);
	return (SUCCESS);
}

int main(void)
{
	t_env e;

	ft_bzero(&e, sizeof(t_env));

	while (ft_gnl(&e))
	{
		if (!check_line(&e))
			return (close_lemin(&e, ERROR_CLOSE));

	}
	// t_room *t;
	// t_lst *tmp;
	// tmp = e.room;
	// while (tmp)
	// {
	// 	t = (t_room*)(tmp->data);
	// 	ft_printf(" ROOM : %s [%d , %d]\n", (char*)t->name, t->pos.x, t->pos.y);
	// 	tmp = tmp->next;
	// }

	return (close_lemin(&e, NORMAL_CLOSE));
}