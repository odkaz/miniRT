/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazumanoda <kazumanoda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 10:57:18 by kazumanoda        #+#    #+#             */
/*   Updated: 2020/12/20 14:36:34 by kazumanoda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		check_normal(t_vector n)
{
	if (n.x == 0 && n.y == 0 && n.z == 0)
		exit_error("unit vector cannot be defined (0, 0, 0)\n");
}

void		skip_to_num(char **line)
{
	while (**line)
	{
		if (cisspace(**line) || **line == ',')
			(*line)++;
		else if (cisnum(**line) || **line == '-')
			break ;
		else
			exit_error("invalid character in rt file\n");
	}
}
