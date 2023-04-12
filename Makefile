# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: goda-sil <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/16 17:24:22 by goda-sil          #+#    #+#              #
#    Updated: 2023/04/06 18:04:36 by goda-sil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = -rm -rf

FUNCTIONS = ./functions/minitalk.a

CLIENT = client
SERVER = server

SOURCE_CLIENT = sources/client.c
OBJECT_CLIENT = $(SOURCE_CLIENT:%.c=%.o)

SOURCE_SERVER = sources/server.c
OBJECT_SERVER = $(SOURCE_SERVER:%.c=%.o)

#Rules:
all: $(SERVER) $(CLIENT)

$(FUNCTIONS):
	@$(MAKE) -C ./functions

$(SERVER): $(OBJECT_SERVER) $(FUNCTIONS)
	@$(CC) $(CFLAGS) $(OBJECT_SERVER) $(FUNCTIONS) -o server

$(CLIENT): $(OBJECT_CLIENT) $(FUNCTIONS)
	@$(CC) $(CFLAGS) $(OBJECT_CLIENT) $(FUNCTIONS) -o client

clean:
	@$(MAKE) clean -C ./functions
	@$(RM) $(OBJECT_CLIENT) $(OBJECT_SERVER)

fclean: clean
	@$(MAKE) fclean -C ./functions
	@$(RM) $(SERVER) $(CLIENT)

re: fclean all
