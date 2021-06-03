/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd_2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssamadi <ssamadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 17:26:05 by ssamadi           #+#    #+#             */
/*   Updated: 2021/05/31 12:21:50 by ssamadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe_h_bonus.h"

int	chek_fre(t_norm	norm)
{
	if (norm.ck == 2)
	{
		free(norm.path);
		return (2);
	}
	else if (norm.ck == -1)
	{
		free(norm.path);
		return (-1);
	}
	return (0);
}

int	loop_chk_command(t_norm	norm, t_lst *tmp, int pipe)
{
	while (++norm.i != norm.o)
	{
		norm.ck = half_check_w(tmp, norm, pipe);
		if (norm.ck == 2)
		{
			free_cmds(norm.com_path);
			return (2);
		}
		else if (norm.ck == -1)
		{
			free_cmds(norm.com_path);
			return (-1);
		}
	}
	return (0);
}

void	err_this_command(t_lst *tmp, int pipe)
{
	if (pipe == 0)
	{
		write(2, "minishell: ", 11);
		write(2, tmp->cmd, ft_strlen(tmp->cmd));
		write(2, ": ", 2);
		write(2, "command not found\n", 18);
	}
}

int	half_check_c_2(t_lst *tmp, t_norm norm, int pipe)
{
	norm.fs = check_if_command_is_exist(tmp->cmd);
	if (norm.fs == 0)
	{
		tmp->path = ft_strdup(tmp->cmd);
		return (2);
	}
	else if (norm.fs == -1 && norm.i == norm.o - 1)
	{
		print_error_check_commd(tmp, pipe);
		return (-1);
	}
	if (norm.fs == 3)
		return (-1);
	return (0);
}

int	half_check_w(t_lst *tmp, t_norm norm, int pipe)
{
	if (ft_strncmp(tmp->cmd, "/", 1) != 0)
	{
		norm.com_path[norm.i] = ft_strjoin1(norm.com_path[norm.i], "/");
		norm.com_path[norm.i] = ft_strjoin1(norm.com_path[norm.i], tmp->cmd);
		norm.fs = check_if_command_is_exist(norm.com_path[norm.i]);
	}
	else if (ft_strncmp(tmp->cmd, "/", 1) == 0)
	{
		norm.ck = half_check_c_2(tmp, norm, pipe);
		if (norm.ck == 2)
			return (2);
		else if (norm.ck == -1)
			return (-1);
	}
	if (norm.fs > 0)
	{
		tmp->path = ft_strdup(norm.com_path[norm.i]);
		return (2);
	}
	else if (norm.fs == -1 && norm.i == norm.o - 1)
		err_this_command(tmp, pipe);
	return (0);
}
