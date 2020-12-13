/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazumanoda <kazumanoda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 12:52:45 by kazumanoda        #+#    #+#             */
/*   Updated: 2020/12/13 10:50:55 by kazumanoda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int			atoishift(char **line)
{
	int		res;

	res = 0;
	while (cisnum(**line))
	{
		res = res * 10 + (**line - '0');
		(*line)++;
	}
	return (res);
}

double		decshift(char **line)
{
	double	res;
	int		unit;

	if (**line == '.')
		(*line)++;
	else
		return (0.0);
	res = 0.0;
	unit = 1;
	while (cisnum(**line))
	{
		res = res + (**line - '0') * pow(10, -unit);
		unit++;
		(*line)++;
	}
	return (res);
}

int			cisspace(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

double		nextnum(char **line, double min, double max)
{
	double		res;

	while (cisspace(**line) || **line == ',')
		(*line)++;
	if (**line == '-')
	{
		(*line)++;
		res = -atoishift(line);
		res -= decshift(line);
	}
	else
	{
		res = atoishift(line);
		res += decshift(line);
	}
	if (min != 1)
		if (res < min)
			exit_error("parameter out of boundry\n");
	if (max != -1)
		if (res > max)
			exit_error("parameter out of boundry\n");
	return (res);
}

t_vector	get_vectors(char **line, double min, double max)
{
	double		v[3];

	v[0] = nextnum(line, min, max);
	v[1] = nextnum(line, min, max);
	v[2] = nextnum(line, min, max);
	return (init_vector(v[0], v[1], v[2]));
}
