# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssamadi <ssamadi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/30 17:23:30 by ssamadi           #+#    #+#              #
#    Updated: 2021/05/31 12:24:41 by ssamadi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

FLAGS = -Wall -Wextra -Wall

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

SRC_B = bonus/check_cmd3_bonus.c\
	bonus/check_cmd_2_bonus.c\
	bonus/check_command_bonus.c\
	bonus/file_pipe_bonus.c\
	bonus/fun_work_pip_bonus.c\
	bonus/need_pip_bonus.c\
	bonus/path_bonus.c\
	bonus/pipe_2_bonus.c\
	bonus/pipe_fun_bonus.c\
	bonus/pipex_bonus.c\
	bonus/substr_bonus.c

CC = gcc

all: libft1 $(NAME)

$(NAME): $(SRC)
	cp ./libft1/libft.a .
	$(CC) $(FLAGS) $(SRC) libft.a -o $(NAME)

libft1:
	cd libft && $(MAKE) clean

bonus: $(SRC_B)
		cp ./libft1/libft.a .
		$(CC) $(FLAGS) $(SRC_B) libft.a -o $(NAME)


clean: libftclean

libftclean:
	$(MAKE)	-C libft1 clean

fclean: clean
	rm $(NAME) libft.a 
re: fclean all