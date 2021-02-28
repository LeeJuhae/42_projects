# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/26 21:09:22 by juhlee            #+#    #+#              #
#    Updated: 2021/02/28 10:40:41 by ijuhae           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = datastruct

SRCS = main.cpp DataStruct.cpp
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
	./datastruct
