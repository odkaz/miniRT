/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operators2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazumanoda <kazumanoda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 12:53:36 by kazumanoda        #+#    #+#             */
/*   Updated: 2020/12/12 13:38:43 by kazumanoda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	cross(t_vector a, t_vector b)
{
	double		x;
	double		y;
	double		z;

	x = a.y * b.z - a.z * b.y;
	y = a.z * b.x - a.x * b.z;
	z = a.x * b.y - a.y * b.x;
	return (init_vector(x, y, z));
}

t_vector	normalize(t_vector vec)
{
	return (vector_mlt(vec, 1 / norm(vec)));
}

t_vector	get_incident_vec(t_var_list var, t_vector l_pos)
{
	return (vector_sub(var.inter, l_pos));
}
