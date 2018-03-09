/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_r.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 12:14:39 by apopinea          #+#    #+#             */
/*   Updated: 2016/11/27 12:14:46 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_lutil.h"

/*
**	pour le format de s :
**	ft_prtl 	->	ft_prtl/ft_prtl.c
**		write dans un fd une liste de variable suivant un format contenu dans s
**		S -> ptrm en cours de dévelopement
**		s -> char*
**		f -> double
**		d -> long int
**		u -> size_t
**		c -> char
**		E -> errno
**		n -> \n
**		t -> \t
**		0 -> exit
**		R -> __FILE__ (R pour registre)
**		F -> __FUNCTION__
**		L -> __LINE__
**		i -> écrit Error !!! : en rouge plus du texte
**		C + r,g,y,b,m,c,w,1,0 -> couleur
*/

/*
**	ft_error_d	-> ft_error_r.c
**		fd file descriptor
**		s format pour ft_prtl
*/

int		ft_error_d(int fd, const char *s, ...)
{
	va_list		ap;

	if (fd > 0 && s)
	{
		va_start(ap, s);
		ft_prtl(s, &ap, fd);
		va_end(ap);
	}
	return (FAIL);
}

char	ft_error_c(int fd, const char *s, ...)
{
	va_list		ap;

	if (fd > 0 && s)
	{
		va_start(ap, s);
		ft_prtl(s, &ap, fd);
		va_end(ap);
	}
	return (FAIL);
}

void	*ft_error_n(int fd, const char *s, ...)
{
	va_list		ap;

	if (fd > 0 && s)
	{
		va_start(ap, s);
		ft_prtl(s, &ap, fd);
		va_end(ap);
	}
	return (NULL);
}

void	ft_error_v(int fd, const char *s, ...)
{
	va_list		ap;

	if (fd > 0 && s)
	{
		va_start(ap, s);
		ft_prtl(s, &ap, fd);
		va_end(ap);
	}
}
