/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trichert <trichert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 18:58:01 by apopinea          #+#    #+#             */
/*   Updated: 2018/03/04 00:56:23 by trichert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_put_x.h"

void	ft_putstr_fd(char const *s, int fd)
{
	int i;

	if (s)
	{
		i = 0;
		while (s[i])
			++i;
		write(fd, s, i);
	}
}
