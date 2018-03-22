/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trichert <trichert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 17:17:45 by trichert          #+#    #+#             */
/*   Updated: 2018/03/22 19:32:07 by trichert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	get_data(t_env *e)
{
	while (gnl(e))
	{
		if (!check_line(e))
			close_lemin(e, ERROR_CLOSE);
	}
	if (e->n_l == 0)
	{
		ft_error_v(2, "s", "ERROR!\n\tMissing links between room!\n");
		close_lemin(e, ERROR_CLOSE);
	}
}

void		lemin(void)
{
	t_env	e;

	ft_bzero(&e, sizeof(t_env));
	e.n_r = 2;
	get_data(&e);
	if (!(e.status & ERROR) && (e.status & GET_TUBS))
	{
		e.status &= ~GET_TUBS;
		e.ways = (t_way*)ft_memalloc(sizeof(t_way));
		e.ways->next = NULL;
		if (!check_solvability(&e, give_me_room_with_id(&e, END_ID)))
		{
			ft_error_v(2, "s", "ERROR!\n\tNo path between Start/End found!\n");
			close_lemin(&e, ERROR_CLOSE);
		}
		e.status |= SOLVING | TUBS_OK;
	}
	ft_putendl(e.lines);
	if (e.status & SOLVING)
		render_way(&e);
	close_lemin(&e, NORMAL_CLOSE);
}

int			main(void)
{
	lemin();
	return (0);
}
