# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apopinea <apopinea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/14 18:35:24 by apopinea          #+#    #+#              #
#    Updated: 2018/04/26 19:20:28 by apopinea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: lib $(NAME) all clean fclean clean2 fclean2 cleanlib fcleanlib re relib re2

.SUFFIXES:

NAME = "lem-in"

DIR_S =	srcs/
DIR_I = includes/

####### MAIN #######
INC_MAIN	=	lem-in.h

SRC_MAIN	=	id_next_str.c 				\
				int_dup_plus.c				\
				lem_already_here.c			\
				lem_calcul_size.c			\
				lem_calcul_way.c			\
				lem_clear_room.c			\
				lem_close.c 				\
				lem_get_cmd.c				\
				lem_get_nb_fourmis.c		\
				lem_get_normal_room.c		\
				lem_get_rooms.c 			\
				lem_get_tubes.c				\
				lem_init.c 					\
				lem_launch_ants.c			\
				lem_move_ant.c				\
				lem_pre_calcul_way.c		\
				lem_pre_launch_ants.c		\
				lem_print_rooms.c			\
				lem_recoup_way.c			\
				lem_recoup_way2.c			\
				lem_save_rooms.c 			\
				lem_save_tubes.c			\
				lem_save_way_add.c			\
				lem_save_way_sort.c			\
				lem_save_way.c				\
				lem_search_room_name.c		\
				lem_search_way.c			\
				lem_search_way2.c			\
				lem_sup_way.c				\
				lem_trash_line.c 			\
				lem_trash_line2.c 			\
				lem_verif_room_name.c		\
				lem_way_calc_next_noeud.c	\
				lem_way_find.c				\
				main.c						\
				trash_save.c

SRCS = $(addprefix $(DIR_S), $(SRC_MAIN))

SRO = $(SRCS:.c=.o)
SRD = $(SRCS:.c=.d)

DIR_LIBFT = ./libft/
DIR_H_LIBFT = ./libft/includes
LIBFT_A = ./libft/libftprintf.a

DOT_H = $(addprefix $(DIR_I), $(INC_MAIN))

OPT = -I

INCLUDES_FINAL = $(addprefix $(OPT), $(DIR_I))


FLAG = -Wall -Werror -Wextra -MMD


#LDFLAGS = -framework SDL2
#LDFLAGS = -F /Library/Frameworks -framework SDL2

#CFLAGS = -I /Library/Frameworks/SDL2.framework/Headers

all : $(NAME)

$(NAME): lib $(SRO)
	@gcc -o $@ $(SRO) $(LIBFT_A) $(LDFLAGS) $(FLAG)
	@echo "\033[1m\033[32mSuccess : \033[0m compilation \033[33m\033[1m$(NAME)\033[0m\n"

%.o: %.c
	@gcc -o $@ -c $< $(OPT)$(DIR_H_LIBFT) $(INCLUDES_FINAL) $(CFLAGS) $(FLAG)
	@echo "\033[32m\033[1m[OK]\033[0m " $(notdir $<)

lib:
	@make -C $(DIR_LIBFT)

clean:
	@rm -f $(SRO) $(SRD)
	@echo "\033[1m\033[31msuppression $(NAME) *.o\033[0m"

cleanlib:
	@make clean -C $(DIR_LIBFT)

clean2: clean cleanlib

fclean: clean
	@rm -f $(NAME)
	@echo "\033[1m\033[31msuppression $(NAME)\033[0m"

fcleanlib:
	@make fclean -C $(DIR_LIBFT)

fclean2: fclean fcleanlib

re: fclean all

relib: fcleanlib lib

re2: fclean2 all
