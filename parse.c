/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazumanoda <kazumanoda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 12:52:48 by kazumanoda        #+#    #+#             */
/*   Updated: 2020/12/20 15:47:32 by kazumanoda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		count(t_count *cnt, char *line)
{
	if (*line == 'R')
		cnt->r++;
	if (*line == 'A')
		cnt->a++;
	if (*line == 'c' && *(line + 1) != 'y')
		cnt->c++;
	if (*line == 'l')
		cnt->l++;
	if (*line == 's' && *(line + 1) == 'p')
		cnt->sp++;
	if (*line == 'p' && *(line + 1) == 'l')
		cnt->pl++;
	if (*line == 's' && *(line + 1) == 'q')
		cnt->sq++;
	if (*line == 'c' && *(line + 1) == 'y')
		cnt->cy++;
	if (*line == 't' && *(line + 1) == 'r')
		cnt->tr++;
}

void		branch(t_list *list, char *line)
{
	if (*line == 'R')
		parse_r(list, line);
	if (*line == 'A')
		parse_a(list, line);
	if (*line == 'c' && *(line + 1) != 'y')
		parse_c(list, line);
	if (*line == 'l')
		parse_l(list, line);
	if (*line == 's' && *(line + 1) == 'p')
		parse_sp(list, line);
	if (*line == 'p' && *(line + 1) == 'l')
		parse_pl(list, line);
	if (*line == 's' && *(line + 1) == 'q')
		parse_sq(list, line);
	if (*line == 'c' && *(line + 1) == 'y')
		parse_cy(list, line);
	if (*line == 't' && *(line + 1) == 'r')
		parse_tr(list, line);
}

t_list		*malloc_list(t_count *cnt)
{
	t_list	*ls;

	ls = (t_list *)malloc(sizeof(t_list));
	if (!ls)
		exit_error("malloc failed\n");
	ls->cnt = cnt;
	ls->scn = (t_screen *)ft_calloc(cnt->r + 1, sizeof(t_screen));
	ls->sp = (t_sphere *)ft_calloc(cnt->sp + 1, sizeof(t_sphere));
	ls->amb = (t_ambient *)ft_calloc(cnt->a + 1, sizeof(t_ambient));
	ls->cam = (t_camera *)ft_calloc(cnt->c + 1, sizeof(t_camera));
	ls->l = (t_light *)ft_calloc(cnt->l + 1, sizeof(t_light));
	ls->pl = (t_plane *)ft_calloc(cnt->pl + 1, sizeof(t_plane));
	ls->sq = (t_square *)ft_calloc(cnt->sq + 1, sizeof(t_square));
	ls->cy = (t_cylinder *)ft_calloc(cnt->cy + 1, sizeof(t_cylinder));
	ls->tr = (t_triangle *)ft_calloc(cnt->tr + 1, sizeof(t_triangle));
	return (ls);
}

t_list		*parse(char *path)
{
	int		fd;
	char	*line;
	t_count	*cnt;
	t_list	*ls;

	check_path(path);
	cnt = (t_count *)ft_calloc(1, sizeof(t_count));
	fd = open(path, O_RDONLY);
	if (fd < 0)
		exit_error("please check your .rt file path\n");
	while (get_next_line(fd, &line) == 1)
		count(cnt, line);
	close(fd);
	check_capital(cnt);
	ls = malloc_list(cnt);
	fd = open(path, O_RDONLY);
	while (get_next_line(fd, &line) == 1)
		branch(ls, line);
	return (ls);
}
