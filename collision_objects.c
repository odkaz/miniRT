/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_objects.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazumanoda <kazumanoda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 12:50:42 by kazumanoda        #+#    #+#             */
/*   Updated: 2020/12/12 15:01:32 by kazumanoda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double		collision_sp(t_list *ls, int id)
{
	t_sphere	*sp;
	int			i;

	i = id_id(*(ls->cnt), id);
	sp = &(ls->sp[i]);
	sp->var.t = get_t_sp(*sp, ls->base_cam.pos, ls->base_cam.ray);
	if (sp->var.t > 0.0)
	{
		return (sp->var.t);
	}
	return (0);
}

double		collision_pl(t_list *ls, int id)
{
	t_plane		*pl;
	int			i;

	i = id_id(*(ls->cnt), id);
	pl = &(ls->pl[i]);
	pl->var.t = get_t_pl(*pl, ls->base_cam.pos, ls->base_cam.ray);
	if (pl->var.t > 0.0)
	{
		return (pl->var.t);
	}
	return (0);
}

double		collision_tr(t_list *ls, int id)
{
	t_triangle	*tr;
	int			i;
	t_camera	c;

	c = ls->base_cam;
	i = id_id(*(ls->cnt), id);
	tr = &(ls->tr[i]);
	set_normal_tr(tr, tr->p[0], tr->p[1], tr->p[2]);
	tr->var.t = get_t_plane(tr->p[0], tr->var.normal, c.pos, c.ray);
	if (tr->var.t > 0.0 && p_test_tr(*tr, get_tangent(c, tr->var.t)))
	{
		return (tr->var.t);
	}
	return (0);
}

double		collision_sq(t_list *ls, int id)
{
	t_square	*sq;
	int			i;

	i = id_id(*(ls->cnt), id);
	sq = &(ls->sq[i]);
	sq->var.t = get_t_sq(*sq, ls->base_cam.pos, ls->base_cam.ray);
	if (sq->var.t > 0.0)
	{
		if (inner(sq->ver, sq->hor) != 0)
			set_basis_sq(ls, sq);
		sq->var.inter = get_tangent(ls->base_cam, sq->var.t);
		if (inside_sq(*sq, sq->var.inter))
		{
			return (sq->var.t);
		}
	}
	return (0);
}

double		collision_cy(t_list *ls, int id)
{
	t_cylinder	*cy;
	int			i;

	i = id_id(*(ls->cnt), id);
	cy = &(ls->cy[i]);
	cy->norm = normalize(cy->norm);
	cy->var.t = get_t_cy(*cy, ls->base_cam.ray, ls->base_cam.pos);
	if (cy->var.t > 0.0 && len_cy(ls, cy))
		return (cy->var.t);
	else
	{
		cy->var.t = large_t_cy(*cy, ls->base_cam.ray, ls->base_cam.pos);
		if (cy->var.t > 0.0 && len_cy(ls, cy))
			return (cy->var.t);
	}
	return (0);
}
