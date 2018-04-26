/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <apopinea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:19:33 by apopinea          #+#    #+#             */
/*   Updated: 2018/03/16 18:56:32 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_nombre.h"

/*
**	ft_atoi	->	libft/nombre/ft_atoi.c
**		renvoie le nombre (int) ecrit dans la string fournie
**		en paramettre.
*/

int				ft_atoi(char *str)
{
	int		nb;
	int		i;
	int		neg;

	if (!str)
		return (0);
	i = 0;
	nb = 0;
	neg = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r')
		++i;
	if (str[i] == '-' || str[i] == '+')
		neg = (str[i++] == '-') ? -1 : 1;
	while (str[i] >= '0' && str[i] <= '9')
		nb = (nb * 10) + (str[i++] - '0');
	return (neg * nb);
}

/*
**	ft_atoli	->	libft/nombre/ft_atoi.c
**		renvoie le nombre (long int) ecrit dans la string fournie
**		en paramettre int.
*/

long int		ft_atoli(char *str)
{
	long int	nb;
	int			i;
	long int	neg;

	if (!str)
		return (0);
	i = 0;
	nb = 0;
	neg = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r')
		++i;
	if (str[i] == '-' || str[i] == '+')
	{
		neg = (str[i] == '-') ? -1 : 1;
		++i;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - '0');
		++i;
	}
	return (neg * nb);
}

/*
**	ft_atoli_next	->	libft/nombre/ft_atoi.c
**		renvoie le nombre (long int) ecrit dans la string fournie
**		en paramettre et sauvegarde l'indice final (int *i).
*/

long int		ft_atoli_next(char *str, int *i)
{
	long int	nb;
	long int	neg;

	if (!str || !i)
		return (0);
	nb = 0;
	neg = 1;
	while (str[*i] == ' ' || str[*i] == '\t' || str[*i] == '\n' ||
		str[*i] == '\v' || str[*i] == '\f' || str[*i] == '\r')
		++(*i);
	if (str[*i] == '-' || str[*i] == '+')
	{
		neg = (str[*i] == '-') ? -1 : 1;
		++(*i);
	}
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		nb = (nb * 10) + ((str)[*i] - '0');
		++(*i);
	}
	return (neg * nb);
}

long int		ft_atoli_next_direct(char *str, int *i)
{
	long int	nb;
	long int	neg;

	if (!str || !i)
		return (0);
	nb = 0;
	neg = 1;
	if (str[*i] == '-' || str[*i] == '+')
	{
		neg = (str[*i] == '-') ? -1 : 1;
		++(*i);
	}
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		nb = (nb * 10) + ((str)[*i] - '0');
		++(*i);
	}
	return (neg * nb);
}

int		ft_atoi_next_direct_np(char *str, int *i)
{
	int		nb;
	char	neg;

	nb = 0;
	if (str[*i] == '-')
	{
		neg = 1;
		++(*i);
	}
	else if (str[*i] == '+')
	{
		neg = 0;
		++(*i);
	}
	else
		neg = 0;
	while (str[*i] > '/' && str[*i] < ':')
	{
		nb = (nb * 10) + ((str)[*i] - '0');
		++(*i);
	}
	if (neg)
		return (-nb);
	return (nb);
}

/*
**	ft_atoi_next	->	libft/nombre/ft_atoi.c
**		renvoie le nombre (int) ecrit dans la string fournie
**		en paramettre et sauvegarde l'indice final (size_t *i).
*/

int				ft_atoi_next(char *str, size_t *i)
{
	int		nb;
	int		neg;

	if (!str || !i)
		return (0);
	nb = 0;
	neg = 1;
	while (str[*i] == ' ' || str[*i] == '\t' || str[*i] == '\n' ||
		str[*i] == '\v' || str[*i] == '\f' || str[*i] == '\r')
		(*i)++;
	if (str[*i] == '-' || str[*i] == '+')
		neg = (str[(*i)++] == '-') ? -1 : 1;
	while (str[*i] >= '0' && str[*i] <= '9')
		nb = (nb * 10) + ((str)[(*i)++] - '0');
	return (neg * nb);
}

int				ft_atoi_next2(char *str, int *i)
{
	int		nb;
	int		neg;

	if (!str || !i)
		return (0);
	nb = 0;
	neg = 1;
	while (str[*i] == ' ' || str[*i] == '\t' || str[*i] == '\n' ||
		str[*i] == '\v' || str[*i] == '\f' || str[*i] == '\r')
		(*i)++;
	if (str[*i] == '-' || str[*i] == '+')
		neg = (str[(*i)++] == '-') ? -1 : 1;
	while (str[*i] >= '0' && str[*i] <= '9')
		nb = (nb * 10) + ((str)[(*i)++] - '0');
	return (neg * nb);
}
