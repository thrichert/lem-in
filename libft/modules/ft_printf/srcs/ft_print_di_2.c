/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 13:53:16 by apopinea          #+#    #+#             */
/*   Updated: 2017/03/14 13:53:18 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_ft_printf.h"

/*
**		<-- ft_print_di_b_zero -->
**			print si attribut 0
**		ft_loop_setchar_printf -> ft_printf/ft_print_outil.c
**			copy x fois un char dans une chaine a partir du debut de celle ci
**		ft_set_nbr_dot_printf -> ft_printf/ft_print_outil.c
**			copy dans une chaine un nombre en char avec des , entre les millier
**		ft_setstr_printf -> ft_printf/ft_print_outil.c
**			copy dans une chaine une autre a partir du debut
*/

void	ft_print_di_b_zero(t_ft_printf_env *e)
{
	if (e->signe)
	{
		e->buf[e->cur] = e->signe;
		++(e->cur);
	}
	ft_loop_setchar_printf('0', &(e->buf[e->cur]), e->s_width);
	e->cur += e->s_width;
	if (e->config & B_AQ)
		ft_set_nbr_dot_printf(e->stmp, &(e->buf[e->cur]), e->nb_digit, e->tmp);
	else
		ft_setstr_printf(e->stmp, &(e->buf[e->cur]), e->nb_digit);
	e->cur += e->tmp;
}

/*
**		<-- ft_print_di_b_else -->
**			print dans les cas restants
**		ft_loop_setchar_printf -> ft_printf/ft_print_outil.c
**			copy x fois un char dans une chaine a partir du debut de celle ci
**		ft_set_nbr_dot_printf -> ft_printf/ft_print_outil.c
**			copy dans une chaine un nombre en char avec des , entre les millier
**		ft_setstr_printf -> ft_printf/ft_print_outil.c
**			copy dans une chaine une autre a partir du debut
*/

void	ft_print_di_else(t_ft_printf_env *e)
{
	ft_loop_setchar_printf(' ', &(e->buf[e->cur]), e->s_width);
	e->cur += e->s_width;
	if (e->signe)
	{
		e->buf[e->cur] = e->signe;
		++(e->cur);
	}
	ft_loop_setchar_printf('0', &(e->buf[e->cur]), e->s_prec);
	e->cur += e->s_prec;
	if (e->config & B_AQ)
		ft_set_nbr_dot_printf(e->stmp, &(e->buf[e->cur]), e->nb_digit, e->tmp);
	else
		ft_setstr_printf(e->stmp, &(e->buf[e->cur]), e->nb_digit);
	e->cur += e->tmp;
}
