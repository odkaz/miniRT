/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knoda <knoda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 12:52:54 by kazumanoda        #+#    #+#             */
/*   Updated: 2021/12/16 14:14:35 by knoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

double			get_t_pl(t_plane pl, t_vector pos, t_vector ray)
{
	double	numerator;
	double	denominator;

	numerator = inner(vector_sub(pos, pl.pos), pl.var.normal);
	denominator = inner(ray, pl.var.normal);
	if (denominator != 0)
		return (-numerator / denominator);
	return (0.0);
}
