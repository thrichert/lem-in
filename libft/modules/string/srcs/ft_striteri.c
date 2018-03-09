/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 09:27:35 by apopinea          #+#    #+#             */
/*   Updated: 2016/11/08 09:27:37 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_str.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int i;

	i = 0;
	if (s && *f)
		while (*s)
			(*f)(i++, s++);
}
