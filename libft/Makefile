# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebmarque < ebmarque@student.42porto.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/17 18:25:10 by ebmarque          #+#    #+#              #
#    Updated: 2023/06/14 21:16:12 by ebmarque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_isalpha.c ft_isdigit.c ft_isascii.c ft_isalnum.c ft_isprint.c \
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
	ft_strlcpy.c ft_atoi.c ft_calloc.c ft_memchr.c ft_memcmp.c \
	ft_strchr.c ft_strdup.c ft_strlcat.c ft_strncmp.c ft_strnstr.c \
	ft_strrchr.c ft_tolower.c ft_toupper.c ft_substr.c ft_strjoin.c \
	ft_strtrim.c ft_putnbr_fd.c ft_putendl_fd.c ft_putstr_fd.c \
	ft_putchar_fd.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_split.c \
	ft_is_space.c ft_count_words.c ft_free_split.c ft_word_length.c \
	ft_strndup.c get_next_line.c

OBJS = $(SRCS:.c=.o)

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
	ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
	ft_lstclear.c ft_lstiter.c ft_lstmap.c \

BONUS_OBJS = $(BONUS:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

bonus: $(BONUS_OBJS)
	ar rc $(NAME) $(BONUS_OBJS)
