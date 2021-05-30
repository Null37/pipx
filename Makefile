# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssamadi <ssamadi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/30 17:23:30 by ssamadi           #+#    #+#              #
#    Updated: 2021/05/30 20:41:36 by ssamadi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

FLAGS = -Wall -Wextra -Werror

SRC = check_cmd3.c\
	check_cmd_2.c\
	check_command.c\
	path.c\
	substr.c\
	pipex.c\
	file_pipe.c\
	pipe_fun.c\
	pipe_2.c\
	fun_work_pip.c\
	need_pip.c
CC = gcc

all: libft1 $(NAME)

$(NAME): $(SRC)
	cp ./libft1/libft.a .
	$(CC) $(FLAGS) $(SRC) libft.a -o $(NAME)

libft1:
	cd libft && $(MAKE) clean

clean: libftclean

libftclean:
	$(MAKE)	-C libft1 clean

fclean: clean
	rm $(NAME) libft.a 
re: fclean all