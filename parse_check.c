/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazumanoda <kazumanoda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 12:52:25 by kazumanoda        #+#    #+#             */
/*   Updated: 2020/12/12 15:38:27 by kazumanoda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int			check_null(size_t size, void *p)
{
	char	*s;

	s = (char *)p;
	while (size--)
	{
		if (s[size] != 0)
			return (0);
	}
	return (1);
}

int			check_path(char *path)
{
	int		i;

	i = 0;
	while (path[i])
		i++;
	if (i > 4)
		i -= 3;
	if (ft_strcmp(path + i, ".rt") == 0)
		return (1);
	exit_error("could not find the .rt file\n");
	return (0);
}

void		check_capital(t_count *cnt)
{
	if (cnt->r < 1)
		exit_error("resolution not declared\n");
	if (cnt->r > 1)
		exit_error("capital objects can only be declared once\n");
	if (cnt->a < 1)
		exit_error("ambient lighting not declared\n");
	if (cnt->a > 1)
		exit_error("capital objects can only be declared once\n");
}
