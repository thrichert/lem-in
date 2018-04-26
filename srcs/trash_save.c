/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash_save.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <apopinea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 19:06:32 by apopinea          #+#    #+#             */
/*   Updated: 2018/04/26 19:06:44 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lemin.h"

void	trash_save(char **buf, char *s)
{
	char *tmp;

	if (*buf)
	{
		tmp = *buf;
		*buf = ft_strjoin_3(*buf, "\n", s);
		free(tmp);
		return ;
	}
	*buf = s;
}
