# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcadel <gcadel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/10/09 16:14:23 by gcadel            #+#    #+#              #
#    Updated: 2015/11/23 16:43:51 by gcadel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#--------------Compilateur------------------#
CC = cc -g
CFLAGS = -Wall -Wextra -Werror
CFLAGS += -I./includes -I./libft/includes
LIB = -L./libft -lft

#--------------Config-----------------------#
NAME = minishell
PATH_SRC = ./

#--------------Sources----------------------#
SRC =	main.c	\
		builtin_cd.c	\
		builtin_env.c	\
		builtin_setenv.c \
		builtin_unsetenv.c \
		builtins.c \
		childsignals.c  \
		commandprompt.c \
		envmanagement.c \
		signals.c

OBJ = $(addprefix $(PATH_SRC), $(SRC:.c=.o))

#--------------Actions----------------------#
.PHONY: clean fclean re libft_build

all: libft_build $(NAME) 

$(NAME): $(OBJ) 
	$(CC) $(OBJ) -o $(NAME) $(LIB) $(MLX)

libft_build:
	@make -C ./libft

clean:
	make -C ./libft clean
	/bin/rm -Rf $(OBJ)

fclean: clean
	make -C ./libft fclean
	/bin/rm -Rf $(NAME)

re: fclean all
