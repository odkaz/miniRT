/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_tests_cy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazumanoda <kazumanoda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 10:57:31 by kazumanoda        #+#    #+#             */
/*   Updated: 2020/12/13 10:57:32 by kazumanoda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int			check_len_cy(t_cylinder cy, t_vector p)
{
	double	len;

	len = inner(vector_sub(cy.pos, p), cy.norm);
	if (len <= cy.height && len >= 0)
	{
		return (1);
	}
	return (0);
}

int			len_cy(t_list *ls, t_cylinder *cy)
{
	t_vector	pc;
	double		len;

	pc = vector_add(ls->base_cam.pos, vector_mlt(ls->base_cam.ray, cy->var.t));
	len = inner(vector_sub(cy->pos, pc), cy->norm);
	if (len <= cy->height && len >= 0)
	{
		return (1);
	}
	return (0);
}

int			len_test_cy(t_list *ls, t_cylinder *cy, int *min, int i)
{
	t_vector	pc;
	double		len;

	pc = vector_add(ls->base_cam.pos, vector_mlt(ls->base_cam.ray, cy->var.t));
	len = inner(vector_sub(cy->pos, pc), cy->norm);
	if (len <= cy->height && len >= 0)
	{
		if (*min == -1)
			*min = i;
		else if (cy->var.t < ls->cy[*min].var.t)
			*min = i;
		return (1);
	}
	return (0);
}
