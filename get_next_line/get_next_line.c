/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazumanoda <kazumanoda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 01:36:13 by kazumanoda        #+#    #+#             */
/*   Updated: 2020/07/21 03:16:14 by kazumanoda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*split(int *rv, char **line)
{
	char	*tmp;
	char	*res;
	char	*mark;

	tmp = NULL;
	mark = ft_strchr(*line, '\n');
	if ((tmp = ft_substr(*line, 0, mark - *line)))
		if ((res = ft_substr(mark + 1, 0, ft_strlen(mark + 1))))
		{
			free(*line);
			*line = tmp;
			*rv = 1;
			return (res);
		}
	free(tmp);
	*rv = -1;
	return (NULL);
}

void	get_read(int fd, int *rv, char **line)
{
	char	*buf;
	char	*tmp;

	buf = NULL;
	tmp = NULL;
	if ((buf = (char	*)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		if ((*rv = read(fd, buf, BUFFER_SIZE)) != -1)
			if ((tmp = ft_my_strdup(*line)))
			{
				free(*line);
				buf[*rv] = '\0';
				if ((*line = ft_strjoin(tmp, buf)))
				{
					free(tmp);
					free(buf);
					return ;
				}
			}
	free(buf);
	free(tmp);
	*rv = -1;
}

int		get_next_line(int fd, char **line)
{
	int			rv;
	static char	*s;

	rv = 0;
	*line = NULL;
	if (s)
		*line = s;
	while (rv != -1)
	{
		if (*line && ft_strchr(*line, '\n'))
		{
			s = split(&rv, line);
			break ;
		}
		get_read(fd, &rv, line);
		if (rv == 0)
			break ;
	}
	if (rv == -1)
	{
		free(s);
		free(*line);
	}
	return (rv);
}
