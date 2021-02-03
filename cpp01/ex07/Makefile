# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ijuhae <ijuhae@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/03 00:56:10 by ijuhae            #+#    #+#              #
#    Updated: 2021/02/03 14:54:35 by ijuhae           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = replace
FLAGS = -Wall -Wextra -Werror

SRCS_DIR = srcs/
SRCS = main.cpp Sed.cpp

OBJS_DIR = objs/
OBJ = $(SRCS:.cpp=.o)
OBJS = $(addprefix $(OBJS_DIR), $(OBJ))

$(OBJS_DIR)%.o: $(SRCS_DIR)%.cpp
	@mkdir -p $(OBJS_DIR)
	@echo "Compiling: $<"
	@clang++ $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@clang++ $(FLAGS) -o $(NAME) $(OBJS)

all: $(NAME)

clean:
	@echo "Cleaning: $(OBJS_DIR)"
	@rm -rf $(OBJS_DIR)

fclean: clean
	@echo "Cleaning: $(NAME)"
	@rm -f $(NAME)
	@rm test/script.replace

re: fclean all

check: $(NAME)
	./$(NAME) test/script McGonagall 🐈
	@echo
	@echo "=> test/script"
	@echo
	@cat test/script
	@echo
	@echo "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-"
	@echo "=> test/script.replace"
	@echo
	@cat test/script.replace
	@echo
	@echo "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-"
