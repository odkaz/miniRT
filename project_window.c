/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazumanoda <kazumanoda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 08:06:07 by kazumanoda        #+#    #+#             */
/*   Updated: 2020/12/14 08:06:21 by kazumanoda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	project_window(t_list *ls, t_rgb *pixels)
{
	int			x;
	int			y;
	t_screen	s;

	y = 0;
	s = *(ls->scn);
	while (y < s.height)
	{
		x = 0;
		while (x < s.width)
		{
			new_pixel_put(s, x, y, *pixels);
			pixels++;
			x++;
		}
		y++;
	}
}
