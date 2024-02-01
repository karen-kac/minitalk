# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myokono <myokono@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/30 16:58:41 by myokono           #+#    #+#              #
#    Updated: 2024/02/01 14:29:19 by myokono          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a
LIBFT_DIR = libft
LIBFTPRINTF = libftprintf/libftprintf.a
LIBFTPRINTF_DIR = libftprintf

SRCS_SERVER = server.c
SRCS_CLIENT = client.c
OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

all: $(LIBFT) $(LIBFTPRINTF) server client

server: $(OBJS_SERVER)
	$(CC) $(CFLAGS) -o server $(OBJS_SERVER) $(LIBFT) $(LIBFTPRINTF)

client: $(OBJS_CLIENT)
	$(CC) $(CFLAGS) -o client $(OBJS_CLIENT) $(LIBFT) $(LIBFTPRINTF)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(LIBFTPRINTF):
	make -C $(LIBFTPRINTF_DIR)

clean:
	rm -f $(OBJS_SERVER) $(OBJS_CLIENT)
	make -C $(LIBFT_DIR) clean
	make -C $(LIBFTPRINTF_DIR) clean

fclean: clean
	rm -f server client
	rm -f $(LIBFT)
	rm -f $(LIBFTPRINTF)

re: fclean all
