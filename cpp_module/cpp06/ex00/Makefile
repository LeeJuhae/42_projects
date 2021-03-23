# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/26 11:03:49 by ijuhae            #+#    #+#              #
#    Updated: 2021/02/26 16:20:55 by ijuhae           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = convert

SRCS = main.cpp Conversion.cpp
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
	./convert 0
	@echo
	./convert nan
	@echo
	./convert 42.0f
	@echo
	./convert 42.42
	@echo
	./convert -inff
	@echo
	./convert a
	@echo
	./convert 97

.PHONY: all clean fclean re test
