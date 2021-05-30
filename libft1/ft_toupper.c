/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssamadi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 20:05:40 by ssamadi           #+#    #+#             */
/*   Updated: 2019/10/11 20:14:23 by ssamadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int cast)
{
	if (cast >= 'a' && cast <= 'z')
	{
		return (cast - 32);
	}
	else
		return (cast);
}