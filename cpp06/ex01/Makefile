# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juhlee <juhlee@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/26 21:09:22 by juhlee            #+#    #+#              #
#    Updated: 2021/02/26 21:28:13 by juhlee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = seri

SRCS =
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
