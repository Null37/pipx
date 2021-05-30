/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   need_pip.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssamadi <ssamadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 20:35:28 by ssamadi           #+#    #+#             */
/*   Updated: 2021/05/30 20:37:51 by ssamadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe_h.h"

int	start_pipe_1(char **envp, t_lst *tmp, t_norm *norm)
{
	if (tmp->next && tmp->file == NULL)
		norml_pipe(norm);
	else if (tmp->file != NULL)
	{
		if (rid_one_two(tmp, norm) == 1)
			return (1);
		if (rid_two_file(tmp, norm) == 1)
			exit(1);
		red_three(tmp, norm);
	}
	execve(tmp->path, tmp->arg, envp);
	return (1);
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
