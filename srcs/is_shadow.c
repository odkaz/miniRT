/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_shadow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knoda <knoda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 12:52:15 by kazumanoda        #+#    #+#             */
/*   Updated: 2021/12/16 14:14:35 by knoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_vector	find_intersec_all(t_list *ls, int id)
{
	int		tp;

	tp = type(*(ls->cnt), id);
	id = id_id(*(ls->cnt), id);
	if (tp == SP)
		return (ls->sp[id].var.inter);
	else if (tp == PL)
		return (ls->pl[id].var.inter);
	else if (tp == SQ)
		return (ls->sq[id].var.inter);
	else if (tp == TR)
		return (ls->tr[id].var.inter);
	else if (tp == CY)
		return (ls->cy[id].var.inter);
	exit_error("couldn't find intersection\n");
	return (init_vector(0, 0, 0));
}

int			is_shadow(t_list *ls, t_light light, int id)
{
	t_vector		p;
	t_vector		ray;
	int				i;

	p = find_intersec_all(ls, id);
	ray = vector_sub(p, light.pos);
	i = convert_min(0, SP, *(ls->cnt));
	while (i < item_num(ls))
	{
		if (i != id || type(*(ls->cnt), i) == CY)
		{
			if (shadow_sp(ls, ray, light, i))
				return (1);
			if (shadow_pl(ls, ray, light, i))
				return (1);
			if (shadow_sq(ls, ray, light, i))
				return (1);
			if (shadow_cy(ls, ray, light, i))
				return (1);
			if (shadow_tr(ls, ray, light, i))
				return (1);
		}
		i++;
	}
	return (0);
}
