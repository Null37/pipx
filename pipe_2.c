/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssamadi <ssamadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 17:54:00 by ssamadi           #+#    #+#             */
/*   Updated: 2021/05/30 18:11:28 by ssamadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe_h.h"

void	err_command(char *cmd)
{
	write(2, "NULL37:> ", 9);
	write(2, cmd, ft_strlen(cmd));
	write(2, ": command not found", 9);
	write(2, "\n", 1);
}

t_lst	*new_node(char *av)
{
	t_lst	*n;

	n = malloc(sizeof(t_lst));
	n->next = NULL;
	n->arg = ft_split(av, 32);
	n->cmd = n->arg[0];
	n->file = NULL;
	n->type_file = -1;
	return (n);
}

void	add_in_list(t_lst **cmd_list, char *av)
{
	t_lst	*tmp;

	if (*cmd_list == NULL)
	{
		*cmd_list = new_node(av);
		return ;
	}
	tmp = *cmd_list;
	while (1)
	{
		if (tmp->next == NULL)
			break ;
		tmp = tmp->next;
	}
	tmp->next = new_node(av);
}

void	half_add_node2(char **av, t_lst **head, int *count)
{
	int	i;

	i = -1;
	(*count) = 0;
	while (av[++i])
		(*count)++;
	i = 1;
	while (++i < ((*count) - 1))
		add_in_list(head, av[i]);
	if (av[1][0] == '<' && av[1][1] == '<')
	{
		(*head)->file = my_substr(av[1], 2, (int)ft_strlen(av[1]));
		(*head)->type_file = 3;
	}
	else
	{
		(*head)->file = ft_strdup(av[1]);
		(*head)->type_file = 0;
	}
}

void	add_node2(t_lst **head, char **av)
{
	t_lst	*tmp;
	int		count;

	half_add_node2(av, head, &count);
	tmp = *head;
	while (1)
	{
		if (tmp->next == NULL)
			break ;
		tmp = tmp->next;
	}
	if (av[count - 1][0] == '>' && av[count - 1][1] == '>')
	{
		tmp->file = my_substr(av[count - 1], 2, (int)ft_strlen(av[count - 1]));
		tmp->type_file = 2;
	}
	else
	{
		tmp->file = ft_strdup(av[count - 1]);
		tmp->type_file = 1;
	}
}
