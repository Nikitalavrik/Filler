#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nlavrine <nlavrine@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/25 17:55:29 by nlavrine          #+#    #+#              #
#    Updated: 2019/06/25 17:55:30 by nlavrine         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = nlavrine

SRC =	grap_input.c	\
		get_next_line.c	\
		free_map.c		\
		output_map.c	\
		parse.c			\

CC = gcc
FLAGS = -Wall -Wextra -Werror
SRC_DIR = srcs
H_DIR = includes
OBJ_DIR = obj
LIB = libft/libft.a

SRCS = $(addprefix $(SRC_DIR)/,$(SRC))

OBJS = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
		@$(CC) $(FLAGS) $(OBJS) $(LIB) -o $(NAME)
	
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		@mkdir -p $(OBJ_DIR)
		@$(CC) $(FLAGS) -o $@ -c $< -I $(H_DIR)

clean:
	@rm -f $(OBJS)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm $(NAME)

re: fclean all
# $(NAME): $(OBJS)



# clean:
# 	rm -f $(OBJS)
# 	@rm -rf $(OBJ_DIR)

# fclean: clean
# 	rm -f $(NAME)

# re: fclean all
# @$(CC) $(SRCS) get_next_line/libft/libft.a $(FLAGS) get_next_line/get_next_line.c -o $(NAME) 