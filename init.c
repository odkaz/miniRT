/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazumanoda <kazumanoda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 12:51:44 by kazumanoda        #+#    #+#             */
/*   Updated: 2020/12/12 13:31:52 by kazumanoda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	init_vector(double x, double y, double z)
{
	t_vector	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

t_sphere	init_sphere(t_vector pos, double rad)
{
	t_sphere	sp;

	sp.pos = pos;
	sp.rad = rad;
	return (sp);
}

t_camera	init_camera(t_vector pos)
{
	t_camera	cam;

	cam.pos = pos;
	return (cam);
}

t_light		init_light(t_vector pos)
{
	t_light		light;

	light.pos = pos;
	return (light);
}

t_screen	init_screen(int width, int height)
{
	t_screen	screen;

	screen.mlx = mlx_init();
	screen.mlx_win = mlx_new_window(screen.mlx, width, height, "test");
	screen.width = width;
	screen.height = height;
	screen.x = 0;
	screen.y = 0;
	return (screen);
}
