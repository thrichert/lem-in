/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trichert <trichert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 16:55:42 by trichert          #+#    #+#             */
/*   Updated: 2018/03/11 16:21:52 by trichert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define BUF 512

#define ERROR_CLOSE		1
#define NORMAL_CLOSE	2

#define L_IS_COMMENT	1
#define L_IS_BASE_S		2
#define L_IS_BASE_E		3
#define L_IS_BASE		4
#define L_IS_TUNEL		6
#define L_IS_NANTS		7
#define L_IS_WRONG		8

#define R_IS_ROOM		0b0
#define R_IS_FREE		0b1
#define R_IS_OCPY		0b10
#define R_IS_START		0b100
#define R_IS_END		0b1000

#define HAS_ANTS		0b1
#define HAS_START		0b10
#define HAS_END			0b100
#define HAS_PATH		0b1000
#define GET_CMD			0b10000
#define GET_ROOMS		0b100000
#define ROOMS_OK		0b1000000
#define GET_TUBS		0b10000000
#define TUBS_OK			0b100000000
#define SOLVING			0b1000000000
#define IS_SOLVED		0b10000000000
#define ERROR			0b100000000000

typedef struct	s_pos
{
	int x;
	int y;
}				t_pos;

typedef struct	s_room
{
	char	*name;
	char 	stats;
	int 	id;
	t_pos	pos;
	t_lst 	*neighbours;
}				t_room;

typedef struct	s_way
{
	int		l;
	int 	v;
	t_lst	*r;
	struct s_way	*next;
}				t_way;

typedef struct	s_env
{
	char	buf[BUF + 1];
	char 	*lines;
	char	*cline;
	int 	id;
	char	stat_line;
	char 	status;
	int		n_ants;
	int 	n_r;
	int		n_l;
	t_way	*ways;
	int		n_w;
	t_lst 	*room;
}				t_env;

int		close_lemin(t_env *e, char opt);
char	gnl(t_env *e);
