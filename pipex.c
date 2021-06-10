/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssamadi <ssamadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 11:59:25 by ssamadi           #+#    #+#             */
/*   Updated: 2021/05/31 11:57:52 by ssamadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe_h.h"

void	add_all(t_lst **cmd_list, char **av, char **envp, t_norm **norm)
{
	t_lst	*tmp;

	add_node2(cmd_list, av);
	tmp = *cmd_list;
	(*norm)->commandfirst = &tmp->cmd;
	while (1)
	{
		check_this_command(&tmp, envp, 0);
		if (tmp->next == NULL)
			break ;
		tmp = tmp->next;
	}
	(*norm)->commandlast = &tmp->cmd;
}

void	free_ags(t_lst *commands)
{
	int	i;

	i = -1;
	while (commands->arg[++i])
	{
		free(commands->arg[i]);
	}
	free(commands->arg);
}

void	free_list(t_lst *commands)
{
	t_lst	*tmp;

	while (1)
	{
		if (commands)
			tmp = commands->next;
		else
			break ;
		free(commands->file);
		free(commands->path);
		free_ags(commands);
		free(commands);
		commands = tmp;
	}
}

int	main(int ac, char *av[], char **envp)
{
	t_norm	*norm;
	t_lst	*cmd_list;
	int		fd;

	fd = -100;
	cmd_list = NULL;
	if (ac > 4)
	{
		norm = malloc(sizeof(t_norm));
		add_all(&cmd_list, av, envp, &norm);
		pipe_work(envp, &cmd_list, norm);
		fd = open("/tmp/tmpr", O_TRUNC);
		free(norm);
		free_list(cmd_list);
	}
	else
		write(2, "error sytax", 11);
	return (0);
}
