/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knoda <knoda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 12:52:41 by kazumanoda        #+#    #+#             */
/*   Updated: 2021/12/16 14:14:35 by knoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void		parse_r(t_list *ls, char *line)
{
	t_screen	*scn;
	int			i;

	scn = (t_screen *)ft_calloc(1, sizeof(t_screen));
	line++;
	scn->width = nextnum(&line, 0, -1);
	scn->height = nextnum(&line, 0, -1);
	if (scn->width == 0 || scn->height == 0)
		exit_error("screen size must be greater than 0\n");
	i = 0;
	while (!check_null(sizeof(t_screen), &(ls->scn[i])))
	{
		i++;
	}
	ls->scn[i] = *scn;
}

void		parse_a(t_list *ls, char *line)
{
	t_ambient	*amb;
	int			i;

	amb = (t_ambient *)ft_calloc(1, sizeof(t_ambient));
	line++;
	amb->ratio = nextnum(&line, 0, 1);
	amb->rgb[0] = nextnum(&line, 0, 255);
	amb->rgb[1] = nextnum(&line, 0, 255);
	amb->rgb[2] = nextnum(&line, 0, 255);
	i = 0;
	while (!check_null(sizeof(t_ambient), &(ls->amb[i])))
	{
		i++;
	}
	ls->amb[i] = *amb;
}

void		parse_c(t_list *ls, char *line)
{
	t_camera	*cam;
	int			i;

	cam = (t_camera *)ft_calloc(1, sizeof(t_camera));
	line++;
	cam->pos = get_vectors(&line, 1, -1);
	cam->look = get_vectors(&line, 1, -1);
	check_normal(cam->look);
	if (!(cam->look.x == 0 && cam->look.z == 0))
		cam->vup = init_vector(0, -1, 0);
	else
		cam->vup = init_vector(0, 0, -1);
	cam->fov = nextnum(&line, 0, 180);
	if (cam->fov == 0 || cam->fov == 180)
		exit_error("please set fov 0 < a < 180\n");
	i = 0;
	while (!check_null(sizeof(t_camera), &(ls->cam[i])))
		i++;
	ls->cam[i] = *cam;
}

void		parse_l(t_list *ls, char *line)
{
	t_light		*l;
	int			i;

	l = (t_light *)ft_calloc(1, sizeof(t_light));
	line++;
	l->pos = get_vectors(&line, 1, -1);
	l->rad = nextnum(&line, 0, 1);
	l->rgb[0] = nextnum(&line, 0, 255);
	l->rgb[1] = nextnum(&line, 0, 255);
	l->rgb[2] = nextnum(&line, 0, 255);
	i = 0;
	while (!check_null(sizeof(t_light), &(ls->l[i])))
		i++;
	ls->l[i] = *l;
}
