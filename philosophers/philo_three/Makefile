# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juhlee <juhlee@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/23 17:20:47 by juhlee            #+#    #+#              #
#    Updated: 2021/03/23 20:49:54 by juhlee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_three
SRCS = main.c philo_three.c utils.c monitor.c
OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
