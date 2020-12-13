/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_collision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazumanoda <kazumanoda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 12:50:34 by kazumanoda        #+#    #+#             */
/*   Updated: 2020/12/13 11:01:13 by kazumanoda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	new_get_ray(t_camera c, t_screen s)
{
	t_vector	res;
	double		u;
	double		v;

	u = (double)s.x / s.width;
	v = (double)s.y / s.height;
	res = vector_add(c.z, vector_mlt(c.x, u));
	res = vector_add(res, vector_mlt(c.y, v));
	res = vector_sub(res, c.pos);
	return (res);
}

void		compare_min(int *min, double *t, double tmp, int i)
{
	if (*t == 0 && tmp > 0.0)
	{
		*min = i;
		*t = tmp;
	}
	if (tmp > 0.0 && *t > tmp)
	{
		*min = i;
		*t = tmp;
	}
}

int			check_collision(t_list *ls)
{
	int		i;
	int		min;
	double	t;
	double	tmp;

	ls->base_cam.ray = new_get_ray(ls->base_cam, ls->scn[0]);
	i = convert_min(0, SP, *(ls->cnt));
	min = -1;
	t = 0;
	while (i < item_num(ls))
	{
		if (type(*(ls->cnt), i) == SP)
			tmp = collision_sp(ls, i);
		if (type(*(ls->cnt), i) == PL)
			tmp = collision_pl(ls, i);
		if (type(*(ls->cnt), i) == SQ)
			tmp = collision_sq(ls, i);
		if (type(*(ls->cnt), i) == CY)
			tmp = collision_cy(ls, i);
		if (type(*(ls->cnt), i) == TR)
			tmp = collision_tr(ls, i);
		compare_min(&min, &t, tmp, i);
		i++;
	}
	return (min);
}
