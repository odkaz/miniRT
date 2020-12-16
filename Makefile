# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kazumanoda <kazumanoda@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/13 15:01:12 by kazumanoda        #+#    #+#              #
#    Updated: 2020/12/14 10:18:19 by kazumanoda       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := miniRT
CC := gcc
CFLAGS := -Wall -Wextra -Werror
SRCS := cylinder.c cos_pl.c cos_tr.c exit_error.c project_window.c\
		color.c get_byid.c init.c init2.c vector_operators.c \
		vector_operators2.c parse.c bitmap.c \
		get_pixels.c check_collision.c is_shadow.c \
		shadow_manager.c shadow_objects.c set_var_objects.c sphere.c \
		square.c plane.c triangle.c id.c utils.c init_scn.c \
		parse_objects.c parse_objects2.c parse_utils.c parse_utils2.c \
		parse_check.c collision_objects.c utils2.c len_tests_cy.c
OBJS := $(SRCS:.c=.o)
UNAME := $(shell uname)
ifeq ($(UNAME), Linux)
LIBS = -lXext -lX11
RM = rm -f
else
LIBS := ar -rc
MINI := libminirt.a
SUBDIRS = ./get_next_line  ./minilibx_mms_20200219
AOUT = miniRT miniRT.dSYM
endif

ifeq ($(UNAME), Linux)
$(NAME): $(OBJS)
	$(MAKE) -C ./get_next_line
	$(MAKE) -C ./minilibx-linux
	cp ./get_next_line/libget_next_line.a .
	cp ./minilibx-linux/libmlx_linux.a .
	$(CC) main.c $(OBJS) -L. -L.minilibx-linux -lmlx_linux -lget_next_line $(LIBS) -lm -o $(NAME)
all: $(NAME)
clean:
	$(MAKE) clean -C ./get_next_line
	$(MAKE) clean -C ./minilibx-linux
	$(RM) $(OBJS)
fclean: clean
	$(MAKE) fclean -C ./get_next_line
	$(MAKE) clean -C ./minilibx-linux
	$(RM) $(NAME) libmlx_linux.a libget_next_line.a img.bmp
re: fclean all
.PHONY: all clean fclean re .c.o
else
all: $(SUBDIRS) $(NAME)

$(NAME): $(OBJS)
	cp get_next_line/libget_next_line.a $(MINI)
	$(LIBS) $(MINI) $^
	mv minilibx_mms_20200219/libmlx.dylib libmlx.dylib
	$(CC) $(CFLAGS) main.c libmlx.dylib $(MINI) -o $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean: $(SUBDIRS)
	rm -f $(OBJS)
	rm -f $(MINI)

fclean: $(SUBDIRS) clean
	rm -f $(NAME)
	rm libmlx.dylib
	rm -rf $(AOUT)

re: $(SUBDIRS) fclean all

$(SUBDIRS) : FORCE
	make -C $@ $(MAKECMDGOALS)

FORCE:

.PHONY: all clean fclean re
endif
