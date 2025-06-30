CC = cc

CFLAGS = -Wextra -Wall -Werror

SRCS =	error_handling.c init_b_to_a.c init_a_to_b.c main.c rotate_cmnd.c sort_three.c stack_init.c swap_cmnd.c \
		push_cmnd.c rev_rotate_cmnd.c sort_stacks.c split.c stack_utils.c

NAME = push_swap

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	echo "Removing object  files"

fclean: clean
	rm -f $(NAME)
	echo "Removing executable file"

re: fclean all

.PHONY: all clean fclean re
