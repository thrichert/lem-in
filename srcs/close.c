/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trichert <trichert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 15:28:24 by trichert          #+#    #+#             */
/*   Updated: 2018/03/11 01:54:21 by trichert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int close_lemin(t_env *e, char opt)
{
	if (e->lines)
	{
		free(e->lines);
		e->lines = NULL;
	}

	if (e->cline)
	{
		free(e->cline);
		e->cline = NULL;
	}

	if (opt == NORMAL_CLOSE)
	{
		ft_error_v(2, "s", "lem-in stopped and exit correctly\n");
		return (SUCCESS);
	}
	else if (opt == ERROR_CLOSE)
	{
		ft_error_d(2, "s", "lem-in exit after an error occur\n");
		exit(0);
	}
	return (FAIL);
}

