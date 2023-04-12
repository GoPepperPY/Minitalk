# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: goda-sil <goda-sil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 15:16:45 by goda-sil          #+#    #+#              #
#    Updated: 2023/04/06 20:44:02 by goda-sil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk.a

SRCS = ft_putchar_fd.c ft_strlen.c ft_atoi.c ft_isdigit.c ft_strdup.c check_arguments.c printf_utils.c printf_utils_two.c ft_printf.c

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

SRC_OBJS = $(SRCS:.c=.o)

.c.o:
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: $(NAME)

$(NAME): $(SRC_OBJS)
	@$(AR) $(NAME) $(SRC_OBJS)

clean:
	@$(RM) $(SRC_OBJS)

fclean:
	@$(RM) $(SRC_OBJS)
	@$(RM) $(NAME)

re: fclean all
