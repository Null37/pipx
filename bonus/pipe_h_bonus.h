/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_h_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssamadi <ssamadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 12:08:47 by ssamadi           #+#    #+#             */
/*   Updated: 2021/05/31 12:24:21 by ssamadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_H_BONUS_H
# define PIPE_H_BONUS_H

# include <stdio.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <signal.h>
# include <dirent.h>
# include <errno.h>
# include <sys/stat.h>
# include <stdbool.h>
# include <termios.h>
# include <termcap.h>
# include <fcntl.h>
# include "../libft.h"
typedef struct s_norm
{
	int		file;
	char	*filename1;
	char	*filename2;
	char	**commandfirst;
	char	**commandlast;
	char	*path;
	char	*path2;
	int		fd_pipe[2];
	int		j;
	int		i;
	char	*fsf;
	int		lenp;
	char	*tmp33;
	int		ck;
	int		fs;
	char	**com_path;
	int		o;
	int		ck2;
	int		filefd;
	int		read_fd;
	int		write_fd;
	int		file_tmp;
	char	*line;
	char	*buff;
	int		n;
}	t_norm;

typedef struct s_lst
{
	struct s_lst	*next;
	char			*path;
	char			**arg;
	char			*cmd;
	int				i;
	char			*file;
	int				type_file;
}					t_lst;

typedef struct s_libf
{
	long		x;
	int			n;
	int			i;
	char		*str;
	int			i2;
	int			j;
	char		**pm;
	size_t		i3;
	size_t		x3;
	size_t		j3;
	char		*p;
}	t_libftn;

char	**ft_split(char const *str, char c);
char	*search_in_env2(char *variable, char **envp);
void	pipe_work(char **envp, t_lst **cmd_list, t_norm *norm);
char	*ft_strjoin1(char *s1, char *s2);
char	*get_env_name(char *envp);
int		len_of_args(char **args);
int		my_strcmp(char *s1, char *s2);
int		check_this_command(t_lst **tmp, char **evp, int pipe);
void	add_node2(t_lst **head, char **av);
char	*my_substr(char *s, int start, int end);
int		reverce_f(char *buf, char *stop);
int		loop_chk_command(t_norm	norm, t_lst *tmp, int pipe);
int		chek_fre(t_norm	norm);
int		half_check_w(t_lst *tmp, t_norm norm, int pipe);
void	free_cmds(char **cmd);
int		check_if_command_is_exist(char *path_file);
void	print_error_check_commd(t_lst *tmp, int pipe);
void	norml_pipe(t_norm *norm);
int		rid_one_two(t_lst *tmp, t_norm *norm);
void	start_pipe(t_norm *norm);
void	half_red_2(t_norm *norm);
int		start_pipe_1(char **envp, t_lst *tmp, t_norm *norm);
void	half_dub_th(t_norm *norm);
int		rid_two_file(t_lst *tmp, t_norm *norm);
void	red_three(t_lst *tmp, t_norm *norm);
void	parent(t_lst *tmp, t_norm *norm);
#endif
