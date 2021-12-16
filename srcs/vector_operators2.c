/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operators2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knoda <knoda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 12:53:36 by kazumanoda        #+#    #+#             */
/*   Updated: 2021/12/16 14:14:35 by knoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

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
