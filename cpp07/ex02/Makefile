# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juhlee <juhlee@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/28 14:06:31 by juhlee            #+#    #+#              #
#    Updated: 2021/02/28 15:40:09 by juhlee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = array
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
