/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazumanoda <kazumanoda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 12:50:30 by kazumanoda        #+#    #+#             */
/*   Updated: 2020/12/13 10:47:32 by kazumanoda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void			int_lsb_format(unsigned char *add, int val)
{
	*add = (unsigned char)(val);
	*(add + 1) = (unsigned char)(val >> 8);
	*(add + 2) = (unsigned char)(val >> 16);
	*(add + 3) = (unsigned char)(val >> 24);
}

unsigned char	*init_img(t_rgb *rgb, int w, int h)
{
	unsigned char	*img;
	int				raw_img_size;
	int				x;
	int				y;

	raw_img_size = 3 * w * h;
	img = (unsigned char *)ft_calloc(1, raw_img_size);
	if (!img)
		return (NULL);
	y = 0;
	while (y < h)
	{
		x = 0;
		while (x < w)
		{
			img[(x + y * w) * 3 + 2] = (unsigned char)rgb->r;
			img[(x + y * w) * 3 + 1] = (unsigned char)rgb->g;
			img[(x + y * w) * 3 + 0] = (unsigned char)rgb->b;
			rgb++;
			x++;
		}
		y++;
	}
	return (img);
}

void			write_bf_bi(FILE *f, int w, int h)
{
	unsigned char	bf[14];
	unsigned char	bi[40];
	int				filesize;

	filesize = 54 + 3 * w * h;
	ft_bzero(bf, 14);
	ft_bzero(bi, 40);
	bf[0] = 'B';
	bf[1] = 'M';
	int_lsb_format(&(bf[2]), filesize);
	bf[10] = 54;
	bi[0] = 40;
	int_lsb_format(&(bi[4]), w);
	int_lsb_format(&(bi[8]), h);
	bi[12] = 1;
	bi[14] = 24;
	fwrite(bf, 1, 14, f);
	fwrite(bi, 1, 40, f);
}

void			write_img(FILE *f, int w, int h, t_rgb *rgb)
{
	unsigned char	*img;
	int				i;
	unsigned char	pad[3];

	img = init_img(rgb, w, h);
	if (!img)
		exit_error("malloc failed\n");
	ft_memset(pad, 0, 3);
	i = 0;
	while (i < h)
	{
		fwrite(img + (w * (h - i - 1) * 3), 3, w, f);
		fwrite(pad, 1, (4 - (w * 3) % 4) % 4, f);
		i++;
	}
	free(img);
}

void			bitmap_generator(t_list *ls, t_rgb *rgb)
{
	FILE	*f;
	int		w;
	int		h;

	w = ls->scn->width;
	h = ls->scn->height;
	f = fopen("img.bmp", "wb");
	write_bf_bi(f, ls->scn->width, ls->scn->height);
	write_img(f, ls->scn->width, ls->scn->height, rgb);
	fclose(f);
}
