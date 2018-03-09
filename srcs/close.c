/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trichert <trichert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 15:28:24 by trichert          #+#    #+#             */
/*   Updated: 2018/03/09 19:07:50 by trichert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int close_lemin(t_env *e, char opt)
{
	ft_printf("ici");
//	ft_printf("&e->line : %p\n",e->lines);
	if (e->lines)
	{
		free(e->lines);
		e->lines = NULL;
	}
	ft_printf("ici2");

	if (e->cline)
	{
		free(e->cline);
		e->cline = NULL;
	}
	ft_printf("ici3");

	if (opt == NORMAL_CLOSE)
	{
		ft_printf("lem-in stopped and exit correctly\n");
		return (SUCCESS);
	}
	else if (opt == ERROR_CLOSE)
	{
		return (ft_error_d(2, "s", "lem-in exit after an error occur\n"));
	}
	return (FAIL);
}

