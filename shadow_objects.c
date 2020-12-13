/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow_objects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazumanoda <kazumanoda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 12:53:13 by kazumanoda        #+#    #+#             */
/*   Updated: 2020/12/13 01:27:51 by kazumanoda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int			shadow_sp(t_list *ls, t_vector ray, t_light light, int id)
{
	int		tp;
	double	t;

	tp = type(*(ls->cnt), id);
	if (tp != SP)
		return (0);
	id = id_id(*(ls->cnt), id);
	t = get_t_sp(ls->sp[id], light.pos, ray);
	if (t > 0.0 && t < 1.0)
		return (1);
	return (0);
}

int			shadow_pl(t_list *ls, t_vector ray, t_light light, int id)
{
	int		tp;
	double	t;

	tp = type(*(ls->cnt), id);
	if (tp != PL)
		return (0);
	id = id_id(*(ls->cnt), id);
	t = get_t_pl(ls->pl[id], light.pos, ray);
	if (t > 0.0 && t < 1.0)
	{
		return (1);
	}
	return (0);
}

int			shadow_sq(t_list *ls, t_vector ray, t_light light, int id)
{
	int			tp;
	double		t;
	t_vector	p;

	tp = type(*(ls->cnt), id);
	if (tp != SQ)
		return (0);
	id = id_id(*(ls->cnt), id);
	t = get_t_sq(ls->sq[id], light.pos, ray);
	if (t > 0.0 && t < 1.0)
	{
		p = vector_add(light.pos, vector_mlt(ray, t));
		if (inside_sq(ls->sq[id], p))
			return (1);
	}
	return (0);
}

int			shadow_cy(t_list *ls, t_vector ray, t_light light, int id)
{
	int			tp;
	double		t;
	t_vector	p;

	tp = type(*(ls->cnt), id);
	if (tp != CY)
		return (0);
	id = id_id(*(ls->cnt), id);
	t = get_t_cy(ls->cy[id], ray, light.pos);
	p = vector_add(light.pos, vector_mlt(ray, t));
	if (t > 0.0000000001 && t < 0.99999999)
	{
		if (check_len_cy(ls->cy[id], p))
			return (1);
	}
	t = large_t_cy(ls->cy[id], ray, light.pos);
	p = vector_add(light.pos, vector_mlt(ray, t));
	if (t > 0.0000000001 && t < 0.99999999)
	{
		if (check_len_cy(ls->cy[id], p))
			return (1);
	}
	return (0);
}

int			shadow_tr(t_list *ls, t_vector ray, t_light light, int id)
{
	int		tp;
	double	t;

	tp = type(*(ls->cnt), id);
	if (tp != TR)
		return (0);
	id = id_id(*(ls->cnt), id);
	t = get_t_tr(ls->tr[id], light.pos, ray);
	if (t > 0.0 && t < 1.0)
		return (1);
	return (0);
}
