NAME := libget_next_line.a
CC := gcc
CFLAGS := -Wall -Wextra -Werror
LIBS := ar -rc
SRCS := get_next_line.c get_next_line_utils.c
OBJS := $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(LIBS) $(NAME) $^

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
