/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   get_next_line_bonus.c                             :+:    :+:             */
/*                                                    +:+                     */
/*   By: bvan-den <bvan-den@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/01/29 04:24:56 by bvan-den      #+#    #+#                 */
/*   Updated: 2023/01/29 04:24:57 by bvan-den      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

size_t	get_newline_pos(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

char	*ft_strjoin(char *line, char const *buf)
{
	size_t	line_len;
	size_t	buf_len;
	char	*str;

	line_len = ft_strlen(line);
	buf_len = get_newline_pos(buf);
	if (buf[buf_len] == '\n')
		buf_len++;
	str = malloc(sizeof(char) * (line_len + buf_len + 1));
	if (!str)
		return (free(line), NULL);
	ft_memcpy(str, line, line_len + 1);
	ft_strlcat(str, buf, line_len + buf_len + 1);
	free(line);
	return (str);
}

char	*create_line(int fd, char *buf, char *line)
{
	ssize_t	bytes_read;

	if (!line)
		return (NULL);
	while (!ft_strchr(buf, '\n'))
	{
		if (buf[0] != '\0')
		{
			line = ft_strjoin(line, buf);
			if (!line)
				return (NULL);
		}
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			if (bytes_read == -1 || ft_strlen(line) == 0)
				return (free(line), NULL);
			return (line);
		}
		buf[bytes_read] = '\0';
	}
	line = ft_strjoin(line, buf);
	return (line);
}

void	trim_buf(char *buf)
{
	size_t	newline_pos;
	size_t	offset;

	newline_pos = get_newline_pos(buf);
	offset = 1;
	if (buf[newline_pos] == '\0')
		offset = 0;
	ft_strlcpy(
		buf,
		buf + newline_pos + offset,
		ft_strlen(buf) - newline_pos + 1);
}

char	*get_next_line(int fd)
{
	static char	buf[OPEN_MAX][BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || fd >= OPEN_MAX)
		return (NULL);
	line = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!line)
	{
		buf[fd][0] = '\0';
		return (NULL);
	}
	line[0] = '\0';
	line = create_line(fd, buf[fd], line);
	if (!line)
	{
		buf[fd][0] = '\0';
		return (NULL);
	}
	trim_buf(buf[fd]);
	return (line);
}
