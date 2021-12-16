/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knoda <knoda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 08:06:07 by kazumanoda        #+#    #+#             */
/*   Updated: 2021/12/16 14:14:35 by knoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

char	*new_add(void *img, t_screen s)
{
	int			bpp;
	int			size_l;
	int			endian;

	bpp = 8;
	size_l = s.width * s.height;
	endian = 0;
	return (mlx_get_data_addr(img, &bpp, &size_l, &endian));
}

void	set_add(char *add, t_rgb *rgb, int w, int h)
{
	int			x;
	int			y;

	y = 0;
	while (y < h)
	{
		x = 0;
		while (x < w)
		{
			add[(x + y * w) * 4 + 2] = (unsigned char)rgb->r;
			add[(x + y * w) * 4 + 1] = (unsigned char)rgb->g;
			add[(x + y * w) * 4 + 0] = (unsigned char)rgb->b;
			rgb++;
			x++;
		}
		y++;
	}
}

void	create_images(t_list *ls)
{
	t_screen	s;
	void		**img;
	char		**add;
	int			i;

	ft_putstr("creating images");
	s = *(ls->scn);
	i = 0;
	img = (void **)ft_calloc(ls->cnt->c, sizeof(void *));
	add = (char **)ft_calloc(ls->cnt->c, sizeof(char *));
	while (i < ls->cnt->c)
	{
		img[i] = mlx_new_image(s.mlx, s.width, s.height);
		add[i] = new_add(img[i], s);
		set_add(add[i], ls->rgb[i], s.width, s.height);
		write(1, ".", 1);
		i++;
	}
	ls->img = img;
	ls->add = add;
	ft_putstr("done\n");
}

void	project_window(t_list *ls)
{
	t_screen	s;

	s = *(ls->scn);
	create_images(ls);
	mlx_put_image_to_window(s.mlx, s.mlx_win, ls->img[0], 0, 0);
}
