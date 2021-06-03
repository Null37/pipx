/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_pipe_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssamadi <ssamadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 12:16:55 by ssamadi           #+#    #+#             */
/*   Updated: 2021/05/31 12:33:18 by ssamadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe_h_bonus.h"

void	half_dub_th(t_norm *norm)
{
	dup2(norm->filefd, 0);
	dup2(norm->write_fd, 1);
	close(norm->filefd);
}

int	reverce_norm(char **line, char *buff, t_lst *tmp, t_norm *norm)
{
	if (reverce_f(buff, tmp->file) == 2)
	{
		norm->filefd = open("/tmp/tmpr", O_RDONLY);
		half_dub_th(norm);
		free(*line);
		return (1);
	}
	return (0);
}

void	red_three(t_lst *tmp, t_norm *norm)
{
	char	*line;
	char	*buff;

	line = malloc(2048);
	buff = NULL;
	norm->n = 0;
	if (tmp->type_file == 3)
	{
		norm->file_tmp = open("/tmp/tmpr", O_CREAT | O_WRONLY | O_APPEND,
				0644);
		while (1)
		{
			norm->n = read(0, line, 2048);
			if (norm->n < 0)
				break ;
			line[norm->n] = '\0';
			write(norm->file_tmp, line, ft_strlen(line));
			free(buff);
			buff = NULL;
			buff = ft_strdup(line);
			buff[norm->n - 1] = '\0';
			if (reverce_norm(&line, buff, tmp, norm) == 1)
				break ;
		}
	}
}

void	pipe_work(char **envp, t_lst **cmd_list, t_norm *norm)
{
	t_lst	*tmp;

	tmp = *cmd_list;
	norm->read_fd = dup(0);
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
	while (wait(NULL) > 0)
		continue ;
}

int	rid_two_file(t_lst *tmp, t_norm *norm)
{
	if (tmp->type_file == 2)
	{
		norm->filefd = open(tmp->file, O_CREAT | O_WRONLY | O_APPEND,
				0644);
		if (norm->filefd < 0)
		{
			perror("NULL37$> ");
			return (1);
		}
		dup2(norm->filefd, 1);
		dup2(norm->read_fd, 0);
		close(norm->filefd);
	}
	return (0);
}
