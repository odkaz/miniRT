/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_byid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knoda <knoda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 14:06:47 by kazumanoda        #+#    #+#             */
/*   Updated: 2021/12/16 14:14:35 by knoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

double	get_r_byid(t_list *ls, int min)
{
	int		tp;
	int		id;

	tp = type(*(ls->cnt), min);
	id = id_id(*(ls->cnt), min);
	if (tp == SP)
		return (ls->sp[id].var.rgb[0]);
	else if (tp == PL)
		return (ls->pl[id].var.rgb[0]);
	else if (tp == SQ)
		return (ls->sq[id].var.rgb[0]);
	else if (tp == TR)
		return (ls->tr[id].var.rgb[0]);
	else if (tp == CY)
		return (ls->cy[id].var.rgb[0]);
	else
	{
		exit_error("get_r failed\n");
		return (0.0);
	}
}

double	get_g_byid(t_list *ls, int min)
{
	int		tp;
	int		id;

	tp = type(*(ls->cnt), min);
	id = id_id(*(ls->cnt), min);
	if (tp == SP)
		return (ls->sp[id].var.rgb[1]);
	else if (tp == PL)
		return (ls->pl[id].var.rgb[1]);
	else if (tp == SQ)
		return (ls->sq[id].var.rgb[1]);
	else if (tp == TR)
		return (ls->tr[id].var.rgb[1]);
	else if (tp == CY)
		return (ls->cy[id].var.rgb[1]);
	else
	{
		exit_error("get_g failed\n");
		return (0.0);
	}
}

double	get_b_byid(t_list *ls, int min)
{
	int		tp;
	int		id;

	tp = type(*(ls->cnt), min);
	id = id_id(*(ls->cnt), min);
	if (tp == SP)
		return (ls->sp[id].var.rgb[2]);
	else if (tp == PL)
		return (ls->pl[id].var.rgb[2]);
	else if (tp == SQ)
		return (ls->sq[id].var.rgb[2]);
	else if (tp == TR)
		return (ls->tr[id].var.rgb[2]);
	else if (tp == CY)
		return (ls->cy[id].var.rgb[2]);
	else
	{
		exit_error("get_b failed\n");
		return (0.0);
	}
}

double	get_cosa_byid(t_list *ls, int min)
{
	int		tp;
	int		id;

	tp = type(*(ls->cnt), min);
	id = id_id(*(ls->cnt), min);
	if (tp == SP)
		return (ls->sp[id].var.cosa);
	else if (tp == PL)
		return (ls->pl[id].var.cosa);
	else if (tp == SQ)
		return (ls->sq[id].var.cosa);
	else if (tp == TR)
		return (ls->tr[id].var.cosa);
	else if (tp == CY)
		return (ls->cy[id].var.cosa);
	else
	{
		exit_error("get_cosa failed\n");
		return (0.0);
	}
}

double	get_cosg_byid(t_list *ls, int min)
{
	int		tp;
	int		id;

	tp = type(*(ls->cnt), min);
	id = id_id(*(ls->cnt), min);
	if (tp == SP)
		return (ls->sp[id].var.cosg);
	else if (tp == PL)
		return (ls->pl[id].var.cosg);
	else if (tp == SQ)
		return (ls->sq[id].var.cosg);
	else if (tp == TR)
		return (ls->tr[id].var.cosg);
	else if (tp == CY)
		return (ls->cy[id].var.cosg);
	else
	{
		exit_error("get_cosg failed\n");
		return (0.0);
	}
}
