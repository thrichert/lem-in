/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <apopinea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 09:45:25 by apopinea          #+#    #+#             */
/*   Updated: 2018/04/26 19:14:56 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "libft.h"

typedef struct	s_room
{
	char		*name;
	int			x;
	int			y;
	int			state;
	int			*id_next;
	int			n_next;
}				t_room;

typedef struct	s_way
{
	int			*noeuds;
	int			n_noeuds;
	int			size;
}				t_way;

typedef struct	s_ant
{
	int			room;
	int			way;
	int			id_noeud;
}				t_ant;

/*
**	n_ants	: nombre de fourmis
*/

typedef struct	s_lem_env
{
	int			n_ants;
	int			n_s_ants;
	int			id_best_way;
	int			id_room_s;
	int			id_room_e;
	t_room		*rooms;
	int			n_rooms;
	char		*buf;
	t_way		**ways;
	int			n_ways;
	int			n_util_way;
	t_ant		*ants;
}				t_lem_env;

int				id_next_str(char *s, int i);
int				*int_dup_plus(int *s, int l, int n);
char			lem_already_here(t_way *way, int id);
int				lem_calcul_size(t_lem_env *e, int id1, int id2);
void			lem_calcul_way(t_lem_env *e, int id, t_way *way);
void			lem_clear_room(t_lem_env *e);
void			lem_close(int fd, t_lem_env *e, char *s, ...);
void			lem_get_cmd(t_lem_env *e, char *s, t_lst **lst);
void			lem_get_nb_fourmis(t_lem_env *e);
void			lem_get_normal_room(t_lem_env *e, char *s, t_lst **lst);
char			*lem_get_rooms(t_lem_env *e);
void			lem_get_tubes(t_lem_env *e, char *s);
void			lem_init(t_lem_env *e);
void			lem_launch_ants(t_lem_env *e);
void			lem_move_ant(t_lem_env *e, int i);
void			lem_pre_calcul_way(t_lem_env *e);
void			lem_pre_launch_ants(t_lem_env *e);
void			lem_print_rooms(t_lem_env *e);
char			lem_recoup_way(t_lem_env *e, t_way *way);
char			lem_recoup_way2(t_way *way1, t_way *way2);
void			lem_save_rooms(t_lem_env *e, t_lst *lst);
void			lem_save_tubes(t_lem_env *e, int a, int b);
void			lem_save_way_add(t_lem_env *e, t_way *way);
void			lem_save_way_sort(t_lem_env *e, t_way *way);
void			lem_save_way(t_lem_env *e, t_way *way);
int				lem_search_room_name(t_lem_env *e, char *s);
int				lem_search_way(t_lem_env *e);
int				lem_search_way2(t_lem_env *e, int k);
void			lem_sup_way(t_way *way);
char			*lem_trash_line(char **buf);
void			lem_trash_line2(char **s, int *i);
void			lem_verif_room_name(t_lem_env *e, char *s, t_lst *lst);
void			lem_way_calc_next_noeud(t_lem_env *e, int id, t_way *way);
void			lem_way_find(t_lem_env *e, int id, t_way *way);
void			trash_save(char **buf, char *s);

#endif
