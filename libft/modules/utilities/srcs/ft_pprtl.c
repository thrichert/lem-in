/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pprtl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <apopinea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 15:33:31 by apopinea          #+#    #+#             */
/*   Updated: 2018/03/24 19:34:07 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_lutil.h"

void	ft_pprtl(int fd, const char *s, ...)
{
	va_list		ap;

	if (fd > 0 && s)
	{
		va_start(ap, s);
		ft_prtl(s, &ap, fd);
		va_end(ap);
	}
}
