/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssamadi <ssamadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 17:47:01 by ssamadi           #+#    #+#             */
/*   Updated: 2021/05/30 17:36:30 by ssamadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe_h.h"

int	check_if_command_is_exist(char *path_file)
{
	int			fs;

	fs = open(path_file, O_RDONLY);
	close(fs);
	return (fs);
}

void	free_cmds(char **cmd)
{
	int	i;

	i = -1;
	while (cmd[++i])
	{
		free(cmd[i]);
	}
	free(cmd);
}

void	erro_h_chek_c(t_lst *tmp, int pipe)
{
	if (pipe == 0)
	{
		write(2, "minishell: ", 11);
		write(2, tmp->cmd, ft_strlen(tmp->cmd));
		write(2, ": ", 2);
		write(2, "command not found\n", 18);
	}
}

int	half_check_commad(t_lst *tmp, char *path)
{
	if (ft_strncmp(path, "", 1) == 0)
	{
		if (check_if_command_is_exist(tmp->cmd) != 3)
		{
			tmp->path = ft_strdup(tmp->cmd);
			return (2);
		}
	}
	if (ft_strncmp(tmp->cmd, "./", 2) == 0
		|| ft_strncmp(tmp->cmd, "../", 3) == 0)
	{
		if (check_if_command_is_exist(tmp->cmd) == 3)
			return (-1);
		tmp->path = ft_strdup(tmp->cmd);
		return (2);
	}
	return (0);
}

int	check_this_command(t_lst **tmp, char **evp, int pipe)
{
	t_norm	norm;
	int		l;

	if ((*tmp)->cmd == NULL)
		return (-1);
	norm.path = search_in_env2("PATH", evp);
	norm.ck = half_check_commad(*tmp, norm.path);
	l = chek_fre(norm);
	if (l == 2)
		return (2);
	else if (l == -1)
		return (-1);
	norm.com_path = ft_split(norm.path, ':');
	free(norm.path);
	norm.o = len_of_args(norm.com_path);
	norm.i = -1;
	norm.ck2 = loop_chk_command(norm, *tmp, pipe);
	if (norm.ck2 == 2)
		return (2);
	else if (norm.ck2 == -1)
		return (-1);
	if (norm.com_path)
		free_cmds(norm.com_path);
	return (0);
}
