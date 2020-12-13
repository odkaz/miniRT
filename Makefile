# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kazumanoda <kazumanoda@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/13 15:01:12 by kazumanoda        #+#    #+#              #
#    Updated: 2020/12/13 19:33:44 by kazumanoda       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := minirt.a
CC := gcc
CFLAGS := -Wall -Wextra -Werror -g
LIBS := ar -rc
SRCS := cylinder.c cos_pl.c cos_tr.c \
		color.c get_byid.c init.c init2.c vector_operators.c \
		vector_operators2.c parse.c bitmap.c \
		get_pixels.c check_collision.c is_shadow.c \
		shadow_manager.c shadow_objects.c set_var_objects.c sphere.c \
		square.c plane.c triangle.c id.c utils.c init_scn.c \
		parse_objects.c parse_objects2.c parse_utils.c parse_utils2.c \
		parse_check.c collision_objects.c utils2.c len_tests_cy.c
OBJS := $(SRCS:.c=.o)
SUBDIRS = ./get_next_line  ./minilibx_mms_20200219
AOUT = a.out a.out.dSYM

all: $(SUBDIRS) $(NAME)

$(NAME): $(OBJS)
	cp get_next_line/libget_next_line.a $(NAME)
	$(LIBS) $(NAME) $^
	mv minilibx_mms_20200219/libmlx.dylib libmlx.dylib
	$(CC) $(CFLAGS) main.c libmlx.dylib $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean: $(SUBDIRS)
	rm -f $(OBJS)

fclean: $(SUBDIRS) clean
	rm -f $(NAME)
	rm libmlx.dylib
	rm -rf $(AOUT)

re: $(SUBDIRS) fclean all

$(SUBDIRS) : FORCE
	make -C $@ $(MAKECMDGOALS)

FORCE:

.PHONY: all clean fclean re
