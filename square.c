/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazumanoda <kazumanoda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 12:53:20 by kazumanoda        #+#    #+#             */
/*   Updated: 2020/12/12 14:45:23 by kazumanoda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	get_t_sq(t_square sq, t_vector pos, t_vector ray)
{
	double	numerator;
	double	denominator;

	numerator = inner(vector_sub(pos, sq.pos), sq.var.normal);
	denominator = inner(ray, sq.var.normal);
	if (denominator != 0)
		return (-numerator / denominator);
	return (0.0);
}

int		inside_sq(t_square sq, t_vector p)
{
	t_vector	qp;

	qp = vector_sub(p, sq.pos);
	if (((inner(sq.ver, qp) <= sq.size / 2)
	&& (inner(sq.ver, qp) >= -sq.size / 2))
	&& ((inner(sq.hor, qp) <= sq.size / 2)
	&& (inner(sq.hor, qp) >= -sq.size / 2)))
	{
		return (1);
	}
	return (0);
}

void	set_basis_sq(t_list *ls, t_square *sq)
{
	sq->ver = vector_sub(get_tangent(ls->base_cam, sq->var.t), sq->pos);
	sq->ver = normalize(sq->ver);
	sq->hor = cross(sq->ver, sq->var.normal);
	sq->hor = normalize(sq->hor);
}
