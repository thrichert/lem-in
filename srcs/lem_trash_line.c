/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_trash_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <apopinea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 19:05:25 by apopinea          #+#    #+#             */
/*   Updated: 2018/04/26 19:05:50 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lemin.h"

char	*lem_trash_line(char **buf)
{
	char	*s;
	int		i;

	while(gnll(0, &s))
	{
		if (!s)
			return (NULL);
		trash_save(buf, s);
		lem_trash_line2(&s, &i);
		if (s[i] == '#')
		{
			if (s[i + 1] == '#')
				return (s);
			else
				free(s);
		}
		else if (s[i] == '\0')
			break ;
		else
			return (s);
	}
	if (s)
		free(s);
	return (NULL);
}
