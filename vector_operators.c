/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operators.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazumanoda <kazumanoda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 12:53:32 by kazumanoda        #+#    #+#             */
/*   Updated: 2020/12/12 13:19:55 by kazumanoda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	vector_add(t_vector v1, t_vector v2)
{
	v1.x += v2.x;
	v1.y += v2.y;
	v1.z += v2.z;
	return (v1);
}

t_vector	vector_sub(t_vector dest, t_vector start)
{
	dest.x -= start.x;
	dest.y -= start.y;
	dest.z -= start.z;
	return (dest);
}

t_vector	vector_mlt(t_vector base, double times)
{
	base.x *= times;
	base.y *= times;
	base.z *= times;
	return (base);
}

double		inner(t_vector v1, t_vector v2)
{
	double	ip;

	ip = 0.0;
	ip += v1.x * v2.x;
	ip += v1.y * v2.y;
	ip += v1.z * v2.z;
	return (ip);
}

double		norm(t_vector v)
{
	double	n;

	n = 0.0;
	n += v.x * v.x;
	n += v.y * v.y;
	n += v.z * v.z;
	return (sqrt(n));
}
