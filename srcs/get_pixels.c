/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixels.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knoda <knoda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 12:51:25 by kazumanoda        #+#    #+#             */
/*   Updated: 2021/12/16 14:14:35 by knoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void		cam_set_basis(t_camera *c, t_screen s)
{
	t_vector	u;
	t_vector	v;
	t_vector	w;
	double		half_h;
	double		half_w;

	half_h = tan(c->fov / 2 * M_PI / 180);
	half_w = half_h * s.width / s.height;
	w = normalize(vector_sub(c->pos, c->look));
	u = normalize(cross(c->vup, w));
	v = cross(w, u);
	c->z = vector_sub(c->pos, vector_mlt(u, half_w));
	c->z = vector_sub(vector_sub(c->z, vector_mlt(v, half_h)), w);
	c->x = vector_mlt(u, half_w * 2);
	c->y = vector_mlt(v, half_h * 2);
}

t_rgb		*collision_loop(t_list *ls, t_screen *s)
{
	t_rgb		*pixels;
	t_rgb		*res;
	int			min;

	if (!(pixels = (t_rgb	*)malloc(sizeof(t_rgb) \
	* (s->width * s->height + 1))))
		exit_error("malloc failed\n");
	res = pixels;
	s->y = 0;
	while (s->y < s->height)
	{
		s->x = 0;
		while (s->x < s->width)
		{
			min = check_collision(ls);
			if (min != -1)
				*pixels = shadow_manager(ls, min, ls->base_cam);
			else
				*pixels = init_rgb(178, 236, 255);
			s->x++;
			pixels++;
		}
		s->y++;
	}
	return (res);
}

t_rgb		*get_pixels(t_list *ls)
{
	t_screen	*s;

	s = ls->scn;
	cam_set_basis(&(ls->base_cam), ls->scn[0]);
	return (collision_loop(ls, s));
}
