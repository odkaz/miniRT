/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazumanoda <kazumanoda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 00:00:51 by kazumanoda        #+#    #+#             */
/*   Updated: 2020/12/20 14:30:40 by kazumanoda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

char			*get_fname(char *index)
{
	char	*res;
	char	*tmp;
	char	*c;

	c = (char *)ft_calloc(2, sizeof(char));
	c[0] = *index;
	tmp = ft_strjoin("img_", c);
	res = ft_strjoin(tmp, ".bmp");
	free(c);
	free(tmp);
	return (res);
}
