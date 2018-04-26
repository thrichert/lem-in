/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_verif_room_name.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <apopinea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 19:03:10 by apopinea          #+#    #+#             */
/*   Updated: 2018/04/26 19:03:23 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lemin.h"

void	lem_verif_room_name(t_lem_env *e, char *s, t_lst *lst)
{
	int	i;

	if (s[0] == '\0' || s[0] == 'L' || s[0] == '#')
		lem_close(2, e, "s", "ERROR!\n\troom bad name\n");
	i = 0;
	while (s[i])
	{
		if(s[i] == '-')
			lem_close(2, e, "s", "ERROR!\n\troom bad name 2\n");
		++i;
	}
	while(lst)
	{
		if (ft_strcmp_np(s, ((t_room*)(lst->data))->name) == 0)
			lem_close(2, e, "s", "ERROR!\n\tduplicat room name\n");
		lst = lst->next;
	}
}