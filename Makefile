# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aotsala <aotsala@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/17 22:27:48 by aotsala           #+#    #+#              #
#    Updated: 2023/03/31 20:56:42 by aotsala          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = server.c client.c
OBJECTS = $(SOURCES:.c=.o)
NAME = minitalk

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): server client

server: .server_

.server_: server.o
		make -C libft
		$(CC) -o server $< -Llibft -lft
		@touch .server_

client: .client_

.client_: client.o
		make -C libft
		$(CC) -o client $< -Llibft -lft
		@touch .client_

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -f $(OBJECTS)
		make -C libft clean
		@rm -f .server .client

fclean: clean
		rm -f server client libft/libft.a

re: fclean all

.PHONY: all ft_printf clean fclean re server client
