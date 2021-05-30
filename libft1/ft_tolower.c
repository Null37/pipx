/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssamadi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 20:15:01 by ssamadi           #+#    #+#             */
/*   Updated: 2019/10/11 21:06:02 by ssamadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int cast)
{
	if (cast >= 'A' && cast <= 'Z')
		return (cast + 32);
	else
		return (cast);
}
