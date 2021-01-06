# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/05 18:51:40 by ijuhae            #+#    #+#              #
#    Updated: 2021/01/06 15:31:55 by ijuhae           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libasm.a

NA			= nasm
NFLAGS		= -f macho64

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

HDR_DIR		= ./includes
HDR			= $(HDR_DIR)/libasm.h

TESTER		= libasm_test

SRC 		= ft_strlen.s \
			ft_write.s \
			ft_read.s \
			ft_strcmp.s \
			ft_strcpy.s \
			ft_strdup.s

OBJ 		= $(SRC:%.s=%.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@ar rc $(NAME) $(OBJ)

%.o : %.s
	$(NA) $(NFLAGS) $< -o $@

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(TESTER)

re : fclean all

test:
	$(CC) -I$(HDR_DIR) main.c $(NAME) -o $(TESTER)
	./$(TESTER)

.PHONY : all clean fclean re text
