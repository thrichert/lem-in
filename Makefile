# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trichert <trichert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/08 16:56:13 by trichert          #+#    #+#              #
#    Updated: 2018/03/13 00:11:56 by trichert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean, fclean, re, $(NAME)

.SUFFIXES:

NAME = lem-in

DIR_SRCS = srcs/
DIR_INC = includes/

SRCS =	algo.c					\
		close.c					\
		main.c					\
		parser_state_machine.c	\
		parser_stdin.c			\
		printer.c				\
		room.c					\
		tubs.c					\
		util.c

SRC = $(addprefix $(DIR_SRCS), $(SRCS))

INCS = lemin.h

DIR_LIBFT = ./libft/
DIR_H_LIBFT = ./libft/includes
LIBFT_A = ./libft/libftprintf.a

SRO = $(SRC:.c=.o)
SRD = $(SRC:.c=.d)

INC = $(addprefix $(DIR_INC), $(INCS))

FLAG = -Wall -Wextra -Werror -MMD

all : $(NAME)

$(NAME): lib $(SRO)
	@gcc -o $@ $(SRO) $(LIBFT_A) $(FLAG)

lib:
	@make -C $(DIR_LIBFT)

%.o: %.c
	@gcc -o $@ -c $< -I $(DIR_H_LIBFT) -I $(DIR_INC) $(FLAG)
	@echo "\033[32m\033[1m[OK]\033[0m " $(notdir $<)
clean:
	@rm -f $(SRO) $(SRD)
	@echo "\033[1m\033[31msuppression lem-in *.o / *.d\033[0m"

cleanlib:
	@make clean -C $(DIR_LIBFT)

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[1m\033[31msuppression lem-in exe\033[0m"

fcleanlib:
	@make fclean -C $(DIR_LIBFT)

re : fclean all

ree : fclean fcleanlib re

-include $(SRO:.o=.d)