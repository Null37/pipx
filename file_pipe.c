/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssamadi <ssamadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 12:16:55 by ssamadi           #+#    #+#             */
/*   Updated: 2021/05/30 21:03:13 by ssamadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe_h.h"


void	reset_pipe(t_norm **norm)
{
	(*norm)->read_fd = dup(0);
	(*norm)->file_tmp = -100;
}

void	start_pipe(t_norm *norm)
{
	pipe(norm->fd_pipe);
	norm->write_fd = dup( norm->fd_pipe[1]);
	close(norm->fd_pipe[1]);
}

void	norml_pipe(t_norm *norm)
{
	dup2(norm->read_fd, 0);
	dup2(norm->write_fd, 1);
	close(norm->read_fd);
	close(norm->write_fd);
	close(norm->fd_pipe[0]);
	close(norm->fd_pipe[1]);
}



void	half_dub_th(t_norm *norm)
{
	dup2(norm->filefd, 0);
	dup2(norm->write_fd, 1);
	close(norm->filefd);
	
}

void	red_three(t_lst *tmp, t_norm *norm)
{
	char *line;
	char *buff;
	int n;

	line = malloc(2048);
	buff = NULL;
	n = 0;
	if (tmp->type_file == 3)
	{
		norm->file_tmp = open("/tmp/tmpr", O_CREAT | O_WRONLY | O_APPEND,
			0644);
		while((n = read(0, line, 2048)) > 0)
		{
			line[n] = '\0';
			write(norm->file_tmp, line, ft_strlen(line));
			free(buff);
			buff = NULL;
			buff = ft_strdup(line);
			buff[n - 1] = '\0';
			if (reverce_f(buff, tmp->file) == 2)
			{
				norm->filefd = open("/tmp/tmpr", O_RDONLY);
				half_dub_th(norm);
				free(line);
				break;
			}
		}
	}
}



void	parent(t_lst *tmp, t_norm *norm)
{
	close(norm->read_fd);
	close(norm->write_fd);
	if (tmp->next)
	{
		norm->read_fd = dup(norm->fd_pipe[0]);
		close(norm->fd_pipe[0]);
	}
}

void pipe_work(char **envp, t_lst **cmd_list, t_norm *norm)
{
	t_lst *tmp;
	
	tmp = *cmd_list;
	while (tmp)
	{
		norm->fd_pipe[0] = -55;
		norm->fd_pipe[1] = -15;
		if (tmp->next)
			start_pipe(norm);
		else
			norm->write_fd = dup(1);
		if (fork() == 0)
		{
			if (start_pipe_1(envp, tmp, norm) == 1)
				exit(1);
		}
		else
			parent(tmp, norm);
		tmp = tmp->next;
	}
	while (wait(NULL) > 0);
}