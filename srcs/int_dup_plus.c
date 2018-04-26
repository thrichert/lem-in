/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_dup_plus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <apopinea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 18:49:01 by apopinea          #+#    #+#             */
/*   Updated: 2018/04/26 18:49:18 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lemin.h"

int		*int_dup_plus(int *s, int l, int n)
{
	int	i;
	int	*d;

	if(!(d = (int*)malloc(n * sizeof(int))))
		return (NULL);
	i = 0;
	while (i < l)
	{
		d[i] = s[i];
		++i;
	}
	while (i < n)
	{
		d[i] = 0;
		++i;
	}
	return (d);
}
