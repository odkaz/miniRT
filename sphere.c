/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knoda <knoda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 12:53:16 by kazumanoda        #+#    #+#             */
/*   Updated: 2021/12/15 14:12:03 by knoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double		get_t_sp(t_sphere sp, t_vector pos, t_vector ray)
{
	t_quadratic		qd;
	t_vector		d;
	t_vector		s;
	double			r;

	d = ray;
	s = vector_sub(pos, sp.pos);
	r = sp.rad;
	qd.a = norm(d) * norm(d);
	qd.b = 2 * inner(s, d);
	qd.c = norm(s) * norm(s) - r * r;
	qd.d = qd.b * qd.b - 4.0 * qd.a * qd.c;
	if (qd.d < 0.0)
		return (0.0);
	if ((-qd.b - sqrt(qd.d)) / (2 * qd.a) > 0.0)
		return ((-qd.b - sqrt(qd.d)) / (2 * qd.a));
	else
		return ((-qd.b + sqrt(qd.d)) / (2 * qd.a));
}

t_vector	get_tangent(t_camera camera, double t)
{
	t_vector	cam;
	t_vector	ray;

	cam = camera.pos;
	ray = camera.ray;
	return (vector_add(cam, vector_mlt(ray, t)));
}

double		get_cosa(t_var_list ls)
{
	double	cosa;

	cosa = -inner(ls.incident, ls.normal);
	cosa /= sqrt(inner(ls.incident, ls.incident) * inner(ls.normal, ls.normal));
	return (cosa);
}

double		get_cosg(t_var_list ls, t_camera cam)
{
	double		cosg;
	double		w;
	double		spec;
	t_vector	vr;

	spec = 10;
	w = -inner(ls.incident, ls.normal) / inner(ls.normal, ls.normal);
	vr = vector_add(vector_mlt(ls.normal, 2 * w), ls.incident);
	cosg = -inner(vr, cam.ray) / sqrt(inner(vr, vr) * inner(cam.ray, cam.ray));
	if (cosg < 0)
		cosg = 0;
	cosg = pow(cosg, spec);
	return (cosg);
}
