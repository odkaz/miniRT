/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_var_objects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knoda <knoda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 12:53:04 by kazumanoda        #+#    #+#             */
/*   Updated: 2021/12/16 14:14:35 by knoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void		set_var_sp(t_sphere *sp, t_camera cam, t_light l)
{
	t_var_list	*var;

	var = &(sp->var);
	var->inter = get_tangent(cam, var->t);
	var->normal = vector_sub(var->inter, sp->pos);
	var->incident = vector_sub(var->inter, l.pos);
	var->cosa = get_cosa(*var);
	var->cosg = get_cosg(*var, cam);
}

void		set_var_pl(t_var_list *var, t_camera cam, t_light l)
{
	var->inter = get_tangent(cam, var->t);
	var->incident = vector_sub(var->inter, l.pos);
	var->cosa = get_cosa_pl(var);
	var->cosg = get_cosg_pl(*var, cam);
}

void		set_var_sq(t_var_list *var, t_camera cam, t_light l)
{
	var->inter = get_tangent(cam, var->t);
	var->incident = vector_sub(var->inter, l.pos);
	var->cosa = get_cosa_pl(var);
	var->cosg = get_cosg_pl(*var, cam);
}

void		set_var(t_var_list *var, t_camera cam, t_light l)
{
	var->inter = get_tangent(cam, var->t);
	var->incident = vector_sub(var->inter, l.pos);
	var->cosa = get_cosa_tr(var);
	var->cosg = get_cosg_tr(*var, cam);
}

void		set_var_cy(t_cylinder *cy, t_camera cam, t_light l)
{
	t_var_list	*var;

	var = &(cy->var);
	var->inter = get_tangent(cam, var->t);
	var->normal = get_normal_cy(*cy, var->inter);
	var->incident = vector_sub(var->inter, l.pos);
	var->cosa = get_cosa_tr(var);
	var->cosg = get_cosg_tr(*var, cam);
}
