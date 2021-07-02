# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dwanetta <dwanetta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/15 01:41:01 by dwanetta          #+#    #+#              #
#    Updated: 2021/07/02 16:53:29 by dwanetta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
FLAGS = -Wall -Wextra #-Werror
OPTION = -c
LIB = -L libft/
LIBFT = make -C libft
OPTION_LIB = -lft
SRCS =	push_swap.c\
		push.c\
		reverse_rotate.c\
		rotate.c\
		swap.c\
		utils.c\
		create_and_check_stack.c

OBJS_SRCS = ${SRCS:.c=.o}

all: $(NAME)

lf:
		@$(LIBFT)

$(NAME): lf $(OBJS_SRCS)
		@$(CC) $(FLAGS) $(OPTION) $(SRCS)
		@$(CC) $(OBJS_SRCS) -o $(NAME) $(LIB) $(OPTION_LIB)
clean:
		@$(LIBFT) clean
		rm -f $(OBJS_SRCS)
fclean: clean
		rm -f $(NAME)
		@$(LIBFT) fclean
re: fclean all
.PHONY: all clean fclean re
