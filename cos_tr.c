/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cos_tr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazumanoda <kazumanoda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 12:51:06 by kazumanoda        #+#    #+#             */
/*   Updated: 2020/12/13 14:54:09 by kazumanoda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	get_cosa_tr(t_var_list *var)
{
	double		cosa;

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

/*
** if the incident is 90<a<180, reverse the normal
*/

double	get_cosg_tr(t_var_list var, t_camera cam)
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
