/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazumanoda <kazumanoda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 12:53:09 by kazumanoda        #+#    #+#             */
/*   Updated: 2020/12/13 10:53:55 by kazumanoda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_rgb		find_brightest(t_list *ls, int min, double d_var, double s_var)
{
	double	i_s;
	double	rgb[3];
	double	color[3];
	int		i;

	i_s = 255.0;
	i = 0;
	rgb[0] = get_r_byid(ls, min);
	rgb[1] = get_g_byid(ls, min);
	rgb[2] = get_b_byid(ls, min);
	while (i < 3)
	{
		color[i] = rgb[i] * d_var;
		color[i] = ft_max(color[i], i_s * s_var);
		color[i] = ft_max(color[i], rgb[i] * \
		(ls->amb[0].rgb[i] / 255.0) * ls->amb[0].ratio);
		i++;
	}
	return (init_rgb(color[0], color[1], color[2]));
}

void		reflection_set_var(t_list *ls, int id, t_camera cam, t_light l)
{
	int		tp;

	tp = type(*(ls->cnt), id);
	id = id_id(*(ls->cnt), id);
	if (tp == SP)
		set_var_sp(&(ls->sp[id]), cam, l);
	else if (tp == PL)
		set_var_pl(&(ls->pl[id].var), cam, l);
	else if (tp == SQ)
		set_var_sq(&(ls->sq[id].var), cam, l);
	else if (tp == TR)
		set_var(&(ls->tr[id].var), cam, l);
	else if (tp == CY)
		set_var_cy(&(ls->cy[id]), cam, l);
	else
		exit_error("diffuse reflection failed\n");
}

t_var_list	get_var_byid(t_list *ls, int min)
{
	int		tp;
	int		id;

	tp = type(*(ls->cnt), min);
	id = id_id(*(ls->cnt), min);
	if (tp == SP)
		return (ls->sp[id].var);
	else if (tp == PL)
		return (ls->pl[id].var);
	else if (tp == SQ)
		return (ls->sq[id].var);
	else if (tp == TR)
		return (ls->tr[id].var);
	else
		return (ls->cy[id].var);
}

/*
** returns 1 if the norm is facing to the cam
*/

int			test_norm(t_list *ls, int min, t_camera cam)
{
	t_vector	to_cam;
	t_var_list	var;
	double		ip;

	var = get_var_byid(ls, min);
	to_cam = vector_sub(cam.pos, var.inter);
	ip = inner(var.normal, to_cam);
	if (ip < 0)
	{
		return (0);
	}
	return (1);
}

t_rgb		shadow_manager(t_list *ls, int min, t_camera cam)
{
	int			i;
	double		d_var;
	double		s_var;

	i = 0;
	d_var = 0;
	s_var = 0;
	while (i < ls->cnt->l)
	{
		reflection_set_var(ls, min, cam, ls->l[i]);
		if (is_shadow(ls, ls->l[i], min) == 0 && test_norm(ls, min, cam))
		{
			if (get_cosa_byid(ls, min) > 0)
				d_var += get_cosa_byid(ls, min) * ls->l[i].rad;
			if (get_cosg_byid(ls, min) > 0)
				s_var += get_cosg_byid(ls, min) * ls->l[i].rad;
		}
		i++;
	}
	d_var = ft_min(d_var, 1.0);
	s_var = ft_min(s_var, 1.0);
	return (find_brightest(ls, min, d_var, s_var));
}
