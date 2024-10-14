# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/06 14:42:23 by ebmarque          #+#    #+#              #
#    Updated: 2024/10/14 12:08:23 by ebmarque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
LIB_NAME = libpush_swap.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
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
		bonus/checker.c

OBJ_DIR = obj
OBJS = $(SRC:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)/src $(OBJ_DIR)/bonus

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(LIB_NAME) $(OBJS)
	@echo "Linking $(NAME)..."
	@$(CC) src/main.c $(INCLUDE) $(LIB_NAME) $(LIBFT_A) -o $(NAME)
	@echo "$(NAME) built successfully."

$(LIB_NAME): $(OBJS)
	@echo "Building libft..."
	@make -C libft
	@echo "Creating $(LIB_NAME)..."
	@ar rcs $(LIB_NAME) $(OBJS)
	@echo "$(LIB_NAME) created successfully."

bonus: $(LIB_NAME) $(OBJS)
	@echo "Linking checker..."
	@$(CC) bonus/checker.c $(INCLUDE) $(LIB_NAME) $(LIBFT_A) -o checker
	@echo "checker built successfully."

clean:
	@echo "Cleaning up..."
	@make -C libft fclean
	@rm -f $(LIB_NAME)
	@rm -rf $(OBJ_DIR)
	@echo "Cleanup done."

fclean: clean
	@echo "Removing executables..."
	@rm -f $(NAME) checker
	@echo "Executables removed."

re: fclean all

.PHONY: re all clean fclean bonus