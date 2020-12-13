/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazumanoda <kazumanoda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 12:50:46 by kazumanoda        #+#    #+#             */
/*   Updated: 2020/12/13 14:55:01 by kazumanoda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		new_pixel_put(t_screen s, int x, int y, t_rgb rgb)
{
	int		trgb;

	trgb = create_trgb(0, rgb.r, rgb.g, rgb.b);
	mlx_pixel_put(s.mlx, s.mlx_win, x, y, trgb);
}

double		get_trgb_fromid(t_list *ls, int id)
{
	double		trgb;

	trgb = 0.0;
	if (id < ls->cnt->sp)
	{
		trgb = create_trgb(0, ls->sp[id].var.rgb[0],\
		ls->sp[id].var.rgb[1], ls->sp[id].var.rgb[2]);
	}
	return (trgb);
}

int			create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
