# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebmarque < ebmarque@student.42porto.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/06 14:42:23 by ebmarque          #+#    #+#              #
#    Updated: 2023/06/17 11:44:21 by ebmarque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

PUSH_LIB = push_swap.a

CC = cc -Wall -Wextra -Werror -g

INCLUDE = -I ./includes

LIBFT_A = libft/libft.a

SRC = 	src/panic.c \
		src/game_init.c \
		src/list_utils.c \
		src/moves1.c \
		src/moves2.c \
		src/dumb.c \
		src/aux.c \
		src/choose_algo.c \
		src/midle_point_a.c \
		src/midle_point_utils.c \
		src/hard_code_utils.c \
		src/hard_code.c \
		bonus/checker.c \
		

OBJS = ${SRC:.c=.o}

all: $(NAME)

$(NAME): $(PUSH_LIB) $(OBJS)
	@$(CC) src/main.c $(INCLUDE) $(PUSH_LIB) $(LIBFT_A) -o $(NAME)

$(PUSH_LIB): $(OBJS)
	@make -C libft
	@ar rcs $(PUSH_LIB) $(LIBFT_A) $(OBJS)

clean:
	@make -C libft/ fclean
	@rm -fr $(PUSH_LIB)
	@rm -fr src/*.o bonus/*.o

fclean: clean
	@rm -fr $(NAME) $(LIBFT_A) checker

re:
	make fclean
	make all
	make bonus
	make clean
	clear

bonus :  $(PUSH_LIB) $(OBJS)
	@$(CC) bonus/checker.c $(INCLUDE) $(PUSH_LIB) $(LIBFT_A) -o checker

	
.PHONY: re all clean fclean