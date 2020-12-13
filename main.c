/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazumanoda <kazumanoda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 12:52:20 by kazumanoda        #+#    #+#             */
/*   Updated: 2020/12/13 10:29:46 by kazumanoda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	exit_error(char *msg)
{
	ft_putstr("ERROR\n");
	ft_putstr(msg);
	exit(1);
}

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

int		main(int argc, char **argv)
{
	t_list		*ls;
	t_screen	*s;

	if (!(argc == 2 || argc == 3))
		exit_error("too few arguments\n");
	ls = parse(argv[1]);
	s = init_scn(ls);
	ls->base_cam = ls->cam[0];
	ls->pixels = get_pixels(ls);
	if (argc == 2)
	{
		project_window(ls, ls->pixels);
		mlx_loop(s->mlx);
	}
	if (argc == 3 && ft_strcmp(argv[2], "--save") == 0)
	{
		ft_putstr("image saved\n");
		bitmap_generator(ls, ls->pixels);
	}
	else
		exit_error("--save to save image\n");
	return (0);
}
