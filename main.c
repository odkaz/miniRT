/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazumanoda <kazumanoda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 12:52:20 by kazumanoda        #+#    #+#             */
/*   Updated: 2020/12/20 15:35:30 by kazumanoda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_all_pixels(t_list *ls)
{
	int		i;

	ft_putstr("tracing rays");
	ls->rgb = (t_rgb **)ft_calloc(ls->cnt->c, sizeof(t_rgb *));
	i = 0;
	while (i < ls->cnt->c)
	{
		ls->base_cam = ls->cam[i];
		ls->rgb[i] = get_pixels(ls);
		i++;
		write(1, ".", 1);
	}
	ls->base_cam = ls->cam[0];
	ft_putstr("done\n");
}

int		main(int argc, char **argv)
{
	t_list		*ls;
	t_screen	*s;

	if (!(argc == 2 || argc == 3))
		exit_error("too few arguments\n");
	ls = parse(argv[1]);
	s = init_scn(ls, argc);
	set_all_pixels(ls);
	if (argc == 2)
	{
		project_window(ls);
		mlx_loop(s->mlx);
	}
	if (argc == 3)
	{
		if (ft_strcmp(argv[2], "--save") == 0)
			bitmap_generator(ls);
		else
			exit_error("--save to save image\n");
	}
	return (0);
}
