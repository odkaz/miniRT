/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knoda <knoda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 12:53:28 by kazumanoda        #+#    #+#             */
/*   Updated: 2021/12/16 14:14:35 by knoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	*ft_memset(void *buf, int ch, size_t n)
{
	unsigned char	*ptr;
	unsigned char	c;

	ptr = (unsigned char	*)buf;
	c = (unsigned char)ch;
	while (n--)
		*ptr++ = c;
	return (buf);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset((unsigned char	*)s, 0, n);
}

void	*ft_calloc(size_t n, size_t size)
{
	void	*res;

	res = (void	*)malloc(size * n);
	if (!res)
		exit_error("malloc failed\n");
	ft_bzero(res, size * n);
	return (res);
}

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char	*)s1;
	str2 = (unsigned char	*)s2;
	while (*str1 || *str2)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	return (0);
}
