# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: krepo <krepo@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/03 12:32:39 by krepo             #+#    #+#              #
#    Updated: 2025/07/03 12:58:42 by krepo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wextra -Wall -Werror

SCRS = error_handling.c init_and_sort_helpers.c init_nodes_b.c \
	   init_nodes.c main.c node_finders.c push_cmnd.c rev_rotate_cmnd.c \
	   rotate_cmnd.c sort_algo.c split.c stack_utils.c swap_cmnd.c

NAME = push_swap

OBJS = $(SCRS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	echo "Removing object files."

fclean: clean
	rm -f $(NAME)
	echo "Removing executble file."

re: fclean all

.PHONY: all clean fclean re
