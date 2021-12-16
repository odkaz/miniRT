/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knoda <knoda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 12:53:24 by kazumanoda        #+#    #+#             */
/*   Updated: 2021/12/16 14:14:35 by knoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

double	get_t_plane(t_vector p, t_vector normal, t_vector pos, t_vector ray)
{
	double	numerator;
	double	denominator;
	double	t;

	numerator = inner(vector_sub(pos, p), normal);
	denominator = inner(ray, normal);
	if (denominator != 0.0)
		t = -numerator / denominator;
	else
		t = 0.0;
	return (t);
}

int		p_test_tr(t_triangle tr, t_vector p)
{
	t_vector	edge[3];
	t_vector	vp[3];
	t_vector	c;

	edge[0] = vector_sub(tr.p[1], tr.p[0]);
	vp[0] = vector_sub(p, tr.p[0]);
	c = cross(edge[0], vp[0]);
	if (inner(tr.var.normal, c) < 0.0)
		return (0);
	edge[1] = vector_sub(tr.p[2], tr.p[1]);
	vp[1] = vector_sub(p, tr.p[1]);
	c = cross(edge[1], vp[1]);
	if (inner(tr.var.normal, c) < 0.0)
		return (0);
	edge[2] = vector_sub(tr.p[0], tr.p[2]);
	vp[2] = vector_sub(p, tr.p[2]);
	c = cross(edge[2], vp[2]);
	if (inner(tr.var.normal, c) < 0.0)
		return (0);
	return (1);
}

double	get_t_tr(t_triangle tr, t_vector pos, t_vector ray)
{
	double		t;
	int			flag;

	t = get_t_plane(tr.p[0], tr.var.normal, pos, ray);
	flag = p_test_tr(tr, vector_add(pos, vector_mlt(ray, t)));
	if (flag)
		return (t);
	return (0);
}

void	set_normal_tr(t_triangle *tr, t_vector pos0, \
t_vector pos1, t_vector pos2)
{
	t_vector	v0v1;
	t_vector	v0v2;

	v0v1 = vector_sub(pos1, pos0);
	v0v2 = vector_sub(pos2, pos0);
	tr->var.normal = cross(v0v1, v0v2);
}
