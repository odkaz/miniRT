/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cos_pl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knoda <knoda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 12:50:56 by kazumanoda        #+#    #+#             */
/*   Updated: 2021/12/16 14:14:35 by knoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

double	get_cosa_pl(t_var_list *var)
{
	double	cosa;

	cosa = -inner(var->incident, var->normal);
	if (cosa < 0)
	{
		var->normal.x = -var->normal.x;
		var->normal.y = -var->normal.y;
		var->normal.z = -var->normal.z;
		cosa = -inner(var->incident, var->normal);
	}
	cosa /= sqrt(inner(var->incident, var->incident) \
	* inner(var->normal, var->normal));
	return (cosa);
}

double	get_cosg_pl(t_var_list var, t_camera cam)
{
	double		cosg;
	double		w;
	double		spec;
	t_vector	vr;

	spec = 20;
	w = -inner(var.incident, var.normal) / inner(var.normal, var.normal);
	vr = vector_add(vector_mlt(var.normal, 2 * w), var.incident);
	cosg = -inner(vr, cam.ray) / sqrt(inner(vr, vr) * inner(cam.ray, cam.ray));
	if (cosg < 0)
		cosg = 0;
	cosg = pow(cosg, spec);
	return (cosg);
}
