/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prtl_llccssierror.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trichert <trichert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 10:41:07 by apopinea          #+#    #+#             */
/*   Updated: 2018/01/20 18:26:43 by trichert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ft_prtl.h"

int		prtl_ll(t_pm_env *e, int i)
{
	int		f;
	char	*str;

	f = (int)va_arg(*e->ap, int);
	str = ft_ldtoa(f);
	ft_putstr_fd("ligne :\033[33m\033[1m ", e->fd);
	ft_putstr_fd(str, e->fd);
	ft_putstr_fd("\n\033[0m", e->fd);
	free(str);
	return (++i);
}

int		prtl_cc(t_pm_env *e, int i)
{
	++i;
	if (e->s[i] == 'r')
		ft_putstr_fd("\033[31m\033[1m", e->fd);
	else if (e->s[i] == 'g')
		ft_putstr_fd("\033[32m\033[1m", e->fd);
	else if (e->s[i] == 'y')
		ft_putstr_fd("\033[33m\033[1m", e->fd);
	else if (e->s[i] == 'b')
		ft_putstr_fd("\033[34m\033[1m", e->fd);
	else if (e->s[i] == 'm')
		ft_putstr_fd("\033[35m\033[1m", e->fd);
	else if (e->s[i] == 'c')
		ft_putstr_fd("\033[36m\033[1m", e->fd);
	else if (e->s[i] == 'w')
		ft_putstr_fd("\033[37m\033[1m", e->fd);
	else if (e->s[i] == '0')
		ft_putstr_fd("\033[0m", e->fd);
	else
	{
		ft_putstr_fd("Format color incorecte\n", e->fd);
		return (-1);
	}
	return (++i);
}

int		prtl_ss(t_pm_env *e, int i)
{
	ft_putstr_fd("S : pas encore implémenté \n", e->fd);
	return (-1);
	if (i)
		return (-1);
}

int		prtl_error(t_pm_env *e, int i)
{
	ft_putstr_fd("Format Incorrecte \n", e->fd);
	return (-1);
	if (i)
		return (-1);
}

int		prtl_i(t_pm_env *e, int i)
{
	ft_putstr_fd("\033[31m\033[1mError !!! \033[0m: ", e->fd);
	return (++i);
}
