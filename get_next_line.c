/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btenzlin <btenzlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 13:29:26 by btenzlin          #+#    #+#             */
/*   Updated: 2022/02/02 13:12:48 by btenzlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*move_to_next(char *str, int start)
{
	char	*s;
	int		count;

	count = 0;
	if (!str || !str[count] || !str[start])
	{
		free(str);
		return (0);
	}
	s = malloc(sizeof(char) * ((ft_strlen(str) - start) + 1));
	if (!s)
		return (0);
	count = 0;
	while (str[start] != '\0')
	{
		s[count] = str[start];
		count++;
		start++;
	}
	s[count] = '\0';
	free(str);
	return (s);
}

static int	size_line(char *save)
{
	int	count;

	count = 0;
	while (save[count] != '\n' && save[count] != '\0')
		count++;
	if (save[count] == '\n')
		count++;
	return (count);
}

static char	*gnl_helper(char *save, char *buf, int fd, int size)
{
	while (size != 0 && !is_eol(save))
	{
		size = read(fd, buf, 42);
		if (size == -1)
		{
			free(buf);
			return (0);
		}
		buf[size] = '\0';
		save = ft_strjoin(save, buf);
	}
	free(buf);
	return (save);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*save;
	char		*line;
	int			size;
	int			count;

	if (fd < 0)
		return (0);
	buf = (char *)malloc(sizeof(char) * (42 + 1));
	if (!buf)
		return (0);
	size = 1;
	save = gnl_helper(save, buf, fd, size);
	if (!save)
		return (0);
	count = size_line(save);
	line = ft_substr(save, 0, count);
	save = move_to_next(save, count);
	return (line);
}
