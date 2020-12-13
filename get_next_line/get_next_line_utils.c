/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazumanoda <kazumanoda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 01:36:27 by kazumanoda        #+#    #+#             */
/*   Updated: 2020/07/14 02:24:55 by kazumanoda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return ((char	*)s);
		s++;
	}
	if (c == '\0')
		return ((char	*)s);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	int		i;
	char	*res;

	len = ft_strlen(s1) + ft_strlen(s2);
	res = (char	*)malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (s1[i])
		*res++ = s1[i++];
	i = 0;
	while (s2[i])
		*res++ = s2[i++];
	res -= len;
	res[len] = '\0';
	return (res);
}

char	*ft_my_strdup(const char *s)
{
	int		i;
	char	*res;

	if (s == NULL)
		return (ft_my_strdup(""));
	res = (char	*)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (s[i])
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*res;

	if (ft_strlen(s) < start)
	{
		if (!(res = (char	*)malloc(1)))
			return (NULL);
		*res = '\0';
		return (res);
	}
	if (!(res = (char	*)malloc((len + 1) * sizeof(char))))
		return (NULL);
	s += start;
	i = 0;
	while (s[i] && i < len)
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
