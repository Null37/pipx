/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssamadi <ssamadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 17:30:35 by ssamadi           #+#    #+#             */
/*   Updated: 2021/05/30 17:30:45 by ssamadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe_h.h"

void	print_error_check_commd(t_lst *tmp, int pipe)
{
	char	*eir;

	if (pipe == 0)
	{
		eir = strerror(errno);
		write(2, "minishell: ", 11);
		write(2, tmp->cmd, ft_strlen(tmp->cmd));
		write(2, ": ", 2);
		write(2, eir, strlen(eir));
		write(2, "\n", 1);
	}
}
