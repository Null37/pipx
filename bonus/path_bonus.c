/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssamadi <ssamadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 14:06:03 by ssamadi           #+#    #+#             */
/*   Updated: 2021/05/31 12:21:33 by ssamadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe_h_bonus.h"

char	*half_h_search(char **envp, t_norm norm)
{
	norm.j += 1;
	while (envp[norm.i][norm.j])
	{
		norm.fsf[0] = envp[norm.i][norm.j];
		norm.buff = ft_strjoin1(norm.buff, norm.fsf);
		norm.j++;
	}
	return (norm.buff);
}

char	*half_search(char *variable, char **envp, t_norm norm)
{
	while (++norm.i < norm.lenp)
	{
		norm.tmp33 = get_env_name(envp[norm.i]);
		if (my_strcmp(norm.tmp33, variable) == 0)
		{
			norm.j = 0;
			while (envp[norm.i][norm.j])
			{
				if (envp[norm.i][norm.j] == '=')
				{
					norm.buff = half_h_search(envp, norm);
					free(norm.tmp33);
					return (norm.buff);
				}
				norm.j++;
			}
			free(norm.buff);
			norm.buff = ft_strdup("k");
			free(norm.tmp33);
			return (norm.buff);
		}
		free(norm.tmp33);
	}
	return (norm.buff);
}

int	my_strcmp(char *s1, char *s2)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	if (!s1 || !s2)
		return (1);
	while (1)
	{
		if (s1[++i] != s2[++j])
			return (1);
		if (s1[i] == '\0' || s2[j] == '\0')
			break ;
	}
	return (0);
}

char	*search_in_env2(char *variable, char **envp)
{
	t_norm	norm;

	norm.j = 0;
	norm.fsf = ft_strdup(" ");
	norm.buff = ft_strdup("");
	norm.lenp = len_of_args(envp);
	norm.i = -1;
	norm.buff = half_search(variable, envp, norm);
	free(norm.fsf);
	return (norm.buff);
}
