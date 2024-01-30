# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myokono <myokono@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/30 16:58:41 by myokono           #+#    #+#              #
#    Updated: 2024/01/30 17:52:37 by myokono          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a
LIBFT_DIR = libft
LIBFTPRINTF = libftprintf/libftprintf.a
LIBFTPRINTF_DIR = libftprintf

SRCS = server.c client.c
OBJS = $(SRCS:.c=.o)

all: $(LIBFT) $(LIBFTPRINTF) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o server server.o $(LIBFT) $(LIBFTPRINTF)
	$(CC) $(CFLAGS) -o client client.o $(LIBFT) $(LIBFTPRINTF)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(LIBFTPRINTF):
	make -C $(LIBFTPRINTF_DIR)

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean
	make -C $(LIBFTPRINTF_DIR) clean

fclean: clean
	rm -f server client
	rm -f $(LIBFT)
	rm -f $(LIBFTPRINTF)

re: fclean all
