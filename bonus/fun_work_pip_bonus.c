/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_work_pip_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssamadi <ssamadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 18:17:11 by ssamadi           #+#    #+#             */
/*   Updated: 2021/05/31 12:21:41 by ssamadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe_h_bonus.h"

void	reset_pipe(t_norm **norm)
{
	(*norm)->read_fd = dup(0);
	(*norm)->file_tmp = -100;
}

void	start_pipe(t_norm *norm)
{
	pipe(norm->fd_pipe);
	norm->write_fd = dup(norm->fd_pipe[1]);
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

int	rid_one_two(t_lst *tmp, t_norm *norm)
{
	if (tmp->type_file == 0)
	{
		norm->filefd = open(tmp->file, O_RDONLY);
		if (norm->filefd < 0)
		{
			perror("NULL37$> ");
			return (1);
		}
		dup2(norm->filefd, 0);
		dup2(norm->write_fd, 1);
		close(norm->filefd);
	}
	else if (tmp->type_file == 1)
	{
		norm->filefd = open(tmp->file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
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

void	half_red_2(t_norm *norm)
{
	norm->filefd = open("/tmp/tmpr", O_RDONLY);
	half_dub_th(norm);
	free(norm->line);
}
