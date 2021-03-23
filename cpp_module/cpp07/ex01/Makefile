# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juhlee <juhlee@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/28 13:28:50 by juhlee            #+#    #+#              #
#    Updated: 2021/02/28 13:29:35 by juhlee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = iter
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)
CC = clang++
FLAGS = -std=c++98 -Wall -Werror -Wextra

$(NAME):
	$(CC) $(FLAGS) $(SRCS) -o $(NAME) -I .

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean:clean
	rm -rf $(NAME)

re: fclean all

test: $(NAME)
	./$(NAME)
