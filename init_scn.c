/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazumanoda <kazumanoda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 12:51:37 by kazumanoda        #+#    #+#             */
/*   Updated: 2020/12/14 10:42:47 by kazumanoda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int			re_render(t_list *ls)
{
	t_screen	*s;

	s = ls->scn;
	free(ls->pixels);
	ls->pixels = get_pixels(ls);
	mlx_clear_window(s->mlx, s->mlx_win);
	project_window(ls, ls->pixels);
	return (0);
}

void		switch_cam(t_list *ls)
{
	if (ls->scn->cam_id < ls->cnt->c - 1)
		ls->scn->cam_id++;
	else
		ls->scn->cam_id = 0;
	ls->base_cam = ls->cam[ls->scn->cam_id];
}

int			key_press(int keycode, t_list *ls)
{
	if (keycode == KEY_ESC)
		exit(0);
	if (keycode == KEY_TAB)
	{
		switch_cam(ls);
		re_render(ls);
	}
	if (keycode == KEY_ESC_VM)
		exit(0);
	if (keycode == KEY_TAB_VM)
	{
		switch_cam(ls);
		re_render(ls);
	}
	return (0);
}

int			close_window(void)
{
	exit(0);
	return (0);
}

t_screen	*init_scn(t_list *ls)
{
	t_screen	*s;
	int			max_x;
	int			max_y;

	s = ls->scn;
	s->mlx = mlx_init();
	mlx_get_screen_size(s->mlx, &max_x, &max_y);
	s->width = (s->width < max_x) ? s->width : max_x;
	s->height = (s->height < max_y) ? s->height : max_y;
	s->mlx_win = mlx_new_window(s->mlx, s->width, s->height, "test");
	mlx_hook(s->mlx_win, KEY_PRESS, 1L << 0, &key_press, ls);
	mlx_hook(s->mlx_win, WIN_CLOSE, 1L << 17, &close_window, ls);
	mlx_hook(s->mlx_win, WIN_MIN, 1L << 21, &re_render, ls);
	s->cam_id = 0;
	return (s);
}
