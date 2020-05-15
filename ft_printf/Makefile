#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/09 20:23:46 by ijuhae            #+#    #+#              #
#    Updated: 2020/05/14 15:52:49 by juhlee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_base_utils.c ft_flag_utils.c ft_extended_split.c ft_init.c\
		ft_mem_utils.c ft_print_utils.c ft_print_utils2.c ft_printf.c \
		ft_unit_info.c ft_digit_utils.c
OBJS = $(SRCS:.c=.o)
LIBFT = ./libft
LIBFT_LIB = libft.a

all : $(NAME)

$(NAME) : $(OBJS)
	@make -C $(LIBFT) 
	cp $(LIBFT)/$(LIBFT_LIB) ./$(NAME)
	$(AR) rc $(NAME) $(OBJS)
	
clean :
	rm -f $(OBJS) 
	make clean -C $(LIBFT)

fclean : clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)

re : fclean all

