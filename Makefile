# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myokono <myokono@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/01 16:23:07 by myokono           #+#    #+#              #
#    Updated: 2024/02/01 16:26:07 by myokono          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SERVER = server
CLIENT = client
SRCS_SERVER = server.c utils.c
SRCS_CLIENT = client.c utils.c
OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)


all: server client

server: $(OBJS_SERVER)
	$(CC) $(CFLAGS) -o server $(OBJS_SERVER)

client: $(OBJS_CLIENT)
	$(CC) $(CFLAGS) -o client $(OBJS_CLIENT)

clean:
	rm -f $(OBJS_SERVER) $(OBJS_CLIENT) $(SERVER) $(CLIENT)

fclean: clean
	rm -f server client

re: fclean all