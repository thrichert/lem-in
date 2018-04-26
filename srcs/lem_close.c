/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_close.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <apopinea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 19:08:58 by apopinea          #+#    #+#             */
/*   Updated: 2018/04/26 19:12:38 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lemin.h"

static void	lem_free_close2(t_lem_env *e)
{
	int i;

	if (e->ways)
	{
		i = 0;
		while (i < e->n_ways)
		{
			if (e->ways[i])
			{
				if (e->ways[i]->noeuds)
				{
					free(e->ways[i]->noeuds);
					e->ways[i]->noeuds = NULL;
				}
				free(e->ways[i]);
				e->ways[i] = NULL;
			}
			++i;
		}
		free(e->ways);
		e->ways = NULL;
	}
	if (e->ants)
		free(e->ants);
	e->ants = NULL;
}

static void	lem_free_close(t_lem_env *e)
{
	int	i;

	if (e == NULL)
		exit(0);
	if (e->rooms)
	{
		i = 0;
		while(i < e->n_rooms)
		{
			if (e->rooms[i].name)
			{
				free(e->rooms[i].name);
				e->rooms[i].name = NULL;
			}
			if (e->rooms[i].id_next)
			{
				free(e->rooms[i].id_next);
				e->rooms[i].id_next = NULL;
			}
			++i;
		}
		free(e->rooms);
		e->rooms = NULL;
	}
	lem_free_close2(e);
}

void		lem_close(int fd, t_lem_env *e, char *s, ...)
{
	va_list		ap;

	if (fd > 0 && s)
	{
		va_start(ap, s);
		ft_prtl(s, &ap, fd);
		va_end(ap);
	}
	lem_free_close(e);
	exit(0);
}
