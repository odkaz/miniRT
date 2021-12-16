/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knoda <knoda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 10:43:14 by kazumanoda        #+#    #+#             */
/*   Updated: 2021/12/16 14:14:35 by knoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

double		ft_max(double a, double b)
{
	return ((a > b) ? a : b);
}

double		ft_min(double a, double b)
{
	return ((a < b) ? a : b);
}

int			cisnum(char c)
{
	return ((c >= '0' && c <= '9'));
}

size_t		ft_strlen_new(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void		ft_putstr(char *s)
{
	write(1, s, ft_strlen_new(s));
}
