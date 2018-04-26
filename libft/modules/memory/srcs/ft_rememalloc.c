/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rememalloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <apopinea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 15:11:18 by apopinea          #+#    #+#             */
/*   Updated: 2018/04/25 17:36:56 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_memory.h"

void	*ft_rememalloc(void *s, size_t l, size_t n)
{
	void	*d;

	if (!(s && l <= n))
		return (NULL);
	if (!(d = (void*)malloc(n)))
		return (NULL);
	ft_memcpy(d, s, l);
	ft_memdel(&s);
	return (d);
}

void	*ft_rememalloc2(void *s, int l, int n)
{
	void	*d;

	if (!s)
		return (malloc(n));
	if (!(d = malloc(n)))
		return (NULL);
	ft_memcpy(d, s, l);
	ft_memdel(&s);
	return (d);
}
