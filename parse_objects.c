/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazumanoda <kazumanoda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 12:52:37 by kazumanoda        #+#    #+#             */
/*   Updated: 2020/12/13 10:50:33 by kazumanoda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		parse_sp(t_list *ls, char *line)
{
	t_sphere	*sp;
	int			i;

	sp = (t_sphere *)ft_calloc(1, sizeof(t_sphere));
	line += 2;
	sp->pos = get_vectors(&line, 1, -1);
	sp->rad = nextnum(&line, 0, -1);
	sp->var.rgb[0] = nextnum(&line, 0, 255);
	sp->var.rgb[1] = nextnum(&line, 0, 255);
	sp->var.rgb[2] = nextnum(&line, 0, 255);
	i = 0;
	while (!check_null(sizeof(t_sphere), &(ls->sp[i])))
		i++;
	ls->sp[i] = *sp;
}

void		parse_pl(t_list *ls, char *line)
{
	t_plane		*pl;
	int			i;

	pl = (t_plane *)ft_calloc(1, sizeof(t_plane));
	line += 2;
	pl->pos = get_vectors(&line, 1, -1);
	pl->var.normal = get_vectors(&line, -1, 1);
	check_normal(pl->var.normal);
	pl->var.rgb[0] = nextnum(&line, 0, 255);
	pl->var.rgb[1] = nextnum(&line, 0, 255);
	pl->var.rgb[2] = nextnum(&line, 0, 255);
	i = 0;
	while (!check_null(sizeof(t_plane), &(ls->pl[i])))
		i++;
	ls->pl[i] = *pl;
}

void		parse_sq(t_list *ls, char *line)
{
	t_square	*sq;
	int			i;

	sq = (t_square *)ft_calloc(1, sizeof(t_square));
	line += 2;
	sq->pos = get_vectors(&line, 1, -1);
	sq->var.normal = get_vectors(&line, -1, 1);
	check_normal(sq->var.normal);
	sq->size = nextnum(&line, 0, -1);
	sq->var.rgb[0] = nextnum(&line, 0, 255);
	sq->var.rgb[1] = nextnum(&line, 0, 255);
	sq->var.rgb[2] = nextnum(&line, 0, 255);
	sq->ver = init_vector(1, 0, 0);
	sq->hor = init_vector(1, 0, 0);
	i = 0;
	while (!check_null(sizeof(t_square), &(ls->sq[i])))
		i++;
	ls->sq[i] = *sq;
}

void		parse_tr(t_list *ls, char *line)
{
	t_triangle	*tr;
	int			i;

	tr = (t_triangle *)ft_calloc(1, sizeof(t_triangle));
	line += 2;
	tr->p[0] = get_vectors(&line, 1, -1);
	tr->p[1] = get_vectors(&line, 1, -1);
	tr->p[2] = get_vectors(&line, 1, -1);
	tr->var.rgb[0] = nextnum(&line, 0, 255);
	tr->var.rgb[1] = nextnum(&line, 0, 255);
	tr->var.rgb[2] = nextnum(&line, 0, 255);
	i = 0;
	while (!check_null(sizeof(t_triangle), &(ls->tr[i])))
		i++;
	ls->tr[i] = *tr;
}

void		parse_cy(t_list *ls, char *line)
{
	t_cylinder	*cy;
	int			i;

	cy = (t_cylinder *)ft_calloc(1, sizeof(t_cylinder));
	line += 2;
	cy->pos = get_vectors(&line, 1, -1);
	cy->norm = get_vectors(&line, -1, 1);
	check_normal(cy->norm);
	cy->var.rgb[0] = nextnum(&line, 0, 255);
	cy->var.rgb[1] = nextnum(&line, 0, 255);
	cy->var.rgb[2] = nextnum(&line, 0, 255);
	cy->r = nextnum(&line, 0, -1);
	cy->height = nextnum(&line, 0, -1);
	i = 0;
	while (!check_null(sizeof(t_cylinder), &(ls->cy[i])))
		i++;
	ls->cy[i] = *cy;
}
