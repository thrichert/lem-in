/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <apopinea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 09:46:05 by apopinea          #+#    #+#             */
/*   Updated: 2018/04/26 19:18:28 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lemin.h"

int		main(void)
{
	t_lem_env	e;

	lem_init(&e);
	lem_pre_calcul_way(&e);
	lem_pre_launch_ants(&e);
	lem_close(1, &e, "");
	return (0);
}
