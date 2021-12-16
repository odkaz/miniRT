/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   id.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knoda <knoda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 12:51:33 by kazumanoda        #+#    #+#             */
/*   Updated: 2021/12/16 14:14:35 by knoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int		convert_min(int min, int type, t_count cnt)
{
	int		n;

	n = cnt.c + cnt.l;
	if (min == -1)
		return (-1);
	if (type == SP)
		return (n + min);
	n += cnt.sp;
	if (type == PL)
		return (n + min);
	n += cnt.pl;
	if (type == SQ)
		return (n + min);
	n += cnt.sq;
	if (type == CY)
		return (n + min);
	n += cnt.cy;
	if (type == TR)
		return (n + min);
	n += cnt.tr;
	exit_error("failed covnert_min\n");
	return (-1);
}

int		type(t_count cnt, int id)
{
	if (id < cnt.c)
		return (CAM);
	id -= cnt.c;
	if (id < cnt.l)
		return (LGT);
	id -= cnt.l;
	if (id < cnt.sp)
		return (SP);
	id -= cnt.sp;
	if (id < cnt.pl)
		return (PL);
	id -= cnt.pl;
	if (id < cnt.sq)
		return (SQ);
	id -= cnt.sq;
	if (id < cnt.cy)
		return (CY);
	id -= cnt.cy;
	if (id < cnt.tr)
		return (TR);
	exit_error("failed finding type\n");
	return (-1);
}

int		id_id(t_count cnt, int id)
{
	if (id < cnt.c)
		return (id);
	id -= cnt.c;
	if (id < cnt.l)
		return (id);
	id -= cnt.l;
	if (id < cnt.sp)
		return (id);
	id -= cnt.sp;
	if (id < cnt.pl)
		return (id);
	id -= cnt.pl;
	if (id < cnt.sq)
		return (id);
	id -= cnt.sq;
	if (id < cnt.cy)
		return (id);
	id -= cnt.cy;
	if (id < cnt.tr)
		return (id);
	exit_error("ERROR in id_id\n");
	return (-1);
}

int		item_num(t_list *ls)
{
	t_count		c;
	int			res;

	res = 0;
	c = *(ls->cnt);
	res += c.c;
	res += c.l;
	res += c.pl;
	res += c.sp;
	res += c.sq;
	res += c.cy;
	res += c.tr;
	return (res);
}
