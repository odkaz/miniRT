# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: knoda <knoda@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/13 15:01:12 by kazumanoda        #+#    #+#              #
#    Updated: 2021/12/16 15:28:00 by knoda            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := miniRT
CC := gcc
CFLAGS := -Wall -Wextra -Werror
SRC_DIR = srcs/
SRC_FILES := cylinder.c cos_pl.c cos_tr.c exit_error.c project_window.c \
		color.c get_byid.c init.c init2.c vector_operators.c \
		vector_operators2.c parse.c bitmap.c \
		get_pixels.c check_collision.c is_shadow.c \
		shadow_manager.c shadow_objects.c set_var_objects.c sphere.c \
		square.c plane.c triangle.c id.c utils.c init_scn.c \
		parse_objects.c parse_objects2.c parse_utils.c parse_utils2.c \
		parse_check.c collision_objects.c utils2.c utils3.c len_tests_cy.c \
		shadow_utils.c main.c
SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJS := $(SRCS:.c=.o)
INCLUDE = -I./includes
UNAME := $(shell uname)

ifeq ($(UNAME), Linux)

LIBS = -lXext -lX11
RM = rm -f

else
LIBS:= get_next_line/libget_next_line.a libx_mac/libmlx.dylib
# LIBS := ar -rc
MINI := libminirt.a
SUBDIRS = ./get_next_line  ./libx_mac
AOUT = miniRT miniRT.dSYM

endif

ifeq ($(UNAME), Linux)

# $(NAME): $(OBJS)
# 	$(MAKE) -C ./get_next_line
# 	$(MAKE) -C ./libx_linux
# 	cp ./get_next_line/libget_next_line.a .
# 	cp ./libx_linux/libmlx_Linux.a .
# 	$(CC) $(OBJS) -L. -L.libx_linux -lmlx_Linux -lget_next_line $(LIBS) -lm -o $(NAME)

# all: $(NAME)

# clean:
# 	$(MAKE) clean -C ./get_next_line
# 	$(MAKE) clean -C ./libx_linux
# 	$(RM) $(OBJS)

# fclean: clean
# 	$(MAKE) fclean -C ./get_next_line
# 	$(MAKE) clean -C ./libx_linux
# 	$(RM) $(NAME) libmlx_linux.a libget_next_line.a img_*

# re: fclean all

# .PHONY: all clean fclean re .c.o

else

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./get_next_line
	$(MAKE) -C ./libx_mac
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) $(LIBS) -o $(NAME)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) clean -C ./get_next_line
	$(MAKE) clean -C ./libx_mac

fclean: clean
	rm -f $(NAME) img_*
	$(MAKE) fclean -C ./get_next_line
	$(MAKE) fclean -C ./libx_mac

re: fclean all
# all: $(SUBDIRS) $(NAME)

# $(NAME): $(OBJS)
# 	cp get_next_line/libget_next_line.a $(MINI)
# 	$(LIBS) $(MINI) $^
# 	mv libx_mac/libmlx.dylib libmlx.dylib
# 	$(CC) $(CFLAGS) $(INCLUDE) libmlx.dylib $(MINI) -o $(NAME)

# .c.o:
# 	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

# clean: $(SUBDIRS)
# 	rm -f $(OBJS)
# 	rm -f $(MINI)

# fclean: $(SUBDIRS) clean
# 	rm -f $(NAME)
# 	rm libmlx.dylib libget_next_line.a img_*
# 	rm -rf $(AOUT)

# re: $(SUBDIRS) fclean all

# $(SUBDIRS) : FORCE
# 	make -C $@ $(MAKECMDGOALS)

# FORCE:

.PHONY: all clean fclean re
endif
