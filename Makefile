# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: goda-sil <goda-sil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/16 17:24:22 by goda-sil          #+#    #+#              #
#    Updated: 2023/04/13 20:54:55 by goda-sil         ###   ########.fr        #
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

CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus

BONUS_CLIENT = sources/client_bonus.c
BONUS_OBJECT_CLIENT = $(BONUS_CLIENT:%.c=%.o)

BONUS_SERVER = sources/server_bonus.c
BONUS_OBJECT_SERVER = $(BONUS_SERVER:%.c=%.o)

#Rules:
all: $(SERVER) $(CLIENT)

$(FUNCTIONS):
	@$(MAKE) -C ./functions

$(SERVER): $(OBJECT_SERVER) $(FUNCTIONS)
	@$(CC) $(CFLAGS) $(OBJECT_SERVER) $(FUNCTIONS) -o server

$(CLIENT): $(OBJECT_CLIENT) $(FUNCTIONS)
	@$(CC) $(CFLAGS) $(OBJECT_CLIENT) $(FUNCTIONS) -o client

$(SERVER_BONUS): $(BONUS_OBJECT_SERVER) $(FUNCTIONS)
	@$(CC) $(CFLAGS) $(BONUS_OBJECT_SERVER) $(FUNCTIONS) -o server_bonus

$(CLIENT_BONUS): $(BONUS_OBJECT_CLIENT) $(FUNCTIONS)
	@$(CC) $(CFLAGS) $(BONUS_OBJECT_CLIENT) $(FUNCTIONS) -o client_bonus

bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

clean:
	@$(MAKE) clean -C ./functions
	@$(RM) $(OBJECT_CLIENT) $(OBJECT_SERVER)
	@$(RM) $(BONUS_OBJECT_SERVER) $(BONUS_OBJECT_CLIENT)

fclean: clean
	@$(MAKE) fclean -C ./functions
	@$(RM) $(SERVER) $(CLIENT)
	@$(RM) $(SERVER_BONUS) $(CLIENT_BONUS)

re: fclean all
