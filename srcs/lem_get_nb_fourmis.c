/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_get_nb_fourmis.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <apopinea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 19:04:19 by apopinea          #+#    #+#             */
/*   Updated: 2018/04/26 19:04:34 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lemin.h"

void	lem_get_nb_fourmis(t_lem_env *e)
{
	char *s;

	s = NULL;
	if(!(s = lem_trash_line(&(e->buf))))
		lem_close(2, e, "s", "ERROR!\n\tno ants\n");
	if ((e->n_ants = ft_atoi(s)) < 1)
		lem_close(2, e, "s", "ERROR!\n\tno ants 2\n");
}
