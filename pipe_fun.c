/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_fun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssamadi <ssamadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 17:48:32 by ssamadi           #+#    #+#             */
/*   Updated: 2021/05/30 20:41:56 by ssamadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe_h.h"

int	len_of_args(char **args)
{
	int		i;

	i = 0;
	while (args[i] != NULL)
		i++;
	return (i);
}

char	*get_env_name(char *envp)
{
	int		b;
	int		c;
	char	*varibale;

	b = 0;
	c = 0;
	while (envp[b])
	{
		if (envp[b] == '=')
			break ;
		b++;
	}
	varibale = malloc(sizeof(char) * b + 1);
	while (c != b)
	{
		varibale[c] = envp[c];
		c++;
	}
	varibale[c] = '\0';
	return (varibale);
}

char	*ft_strjoin1(char *s1, char *s2)
{
	size_t	size;
	char	*str;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!s1)
		return ((str = ft_strdup(s2)));
	size = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	while (s1[++i] != '\0')
		str[i] = s1[i];
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}

int	reverce_f(char *buf, char *stop)
{
	if (ft_strncmp(buf, stop, ft_strlen(stop)) == 0)
		return (2);
	return (0);
}
