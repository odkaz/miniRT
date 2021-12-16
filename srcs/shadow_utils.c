/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knoda <knoda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 14:39:28 by kazumanoda        #+#    #+#             */
/*   Updated: 2021/12/16 14:14:35 by knoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

double		*add_brightness_d(t_list *ls, int min, t_light l, double *var)
{
	double	cosa;
	int		i;

	cosa = get_cosa_byid(ls, min);
	i = 0;
	if (cosa > 0)
	{
		while (i < 3)
		{
			var[i] += cosa * l.rad * l.rgb[i] / 255;
			var[i] = ft_min(var[i], 1.0);
			i++;
		}
	}
	return (var);
}

double		*add_brightness_s(t_list *ls, int min, t_light l, double *var)
{
	double	cosg;
	int		i;

	cosg = get_cosg_byid(ls, min);
	i = 0;
	if (cosg > 0)
	{
		while (i < 3)
		{
			var[i] += cosg * l.rad * l.rgb[i] / 255;
			var[i] = ft_min(var[i], 1.0);
			i++;
		}
	}
	return (var);
}
