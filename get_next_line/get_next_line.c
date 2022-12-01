#include "get_next_line.h"
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
		return (NULL);
	ft_memcpy(str, line, line_len + 1);
	ft_strlcat(str, buf, line_len + buf_len + 1);
	free(line);
	return (str);
}

char	*init_line()
{
	char	*line;

	line = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!line)
		return (NULL);
	line[0] = '\0';
	return (line);
}

char	*create_line(int fd, char *buf, char *line)
{
	ssize_t	bytes_read;

	if (!line)
		return (NULL);
	while (!ft_strchr(buf, '\n'))
	{
		if (buf[0] != '\0')
			line = ft_strjoin(line, buf);
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == 0)
		{
			if (ft_strlen(line) == 0)
				return (NULL);
			else
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

	newline_pos = get_newline_pos(buf);
	ft_strlcpy(buf, buf + newline_pos + 1, ft_strlen(buf) - newline_pos + 1);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;

	line = init_line();
	line = create_line(fd, buf, line);
	if (!line)
	{
		buf[0] = '\0';
		return (NULL);
	}
	trim_buf(buf);
	return (line);
}

char	*get_next_line_old(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	char		tmp[BUFFER_SIZE + 1];
	size_t		newline_pos;
	ssize_t		bytes_read;

	if (ft_strchr(buf, '\n'))
	{
		newline_pos = get_newline_pos(buf);
		line = ft_strndup(buf, newline_pos + 1);
		ft_memcpy(buf, buf + newline_pos + 1, ft_strlen(buf + newline_pos) + 1);
		return (line);
	}
	line = ft_strndup(buf, ft_strlen(buf));
	bytes_read = read(fd, tmp, BUFFER_SIZE);
	if (bytes_read == -1)
		return (buf[0] = '\0', free(line), NULL);
	else if (bytes_read == 0 && ft_strlen(line) > 0)
		return (buf[0] = '\0', line);
	else if (bytes_read == 0)
		return (buf[0] = '\0', free(line), NULL);
	tmp[bytes_read] = '\0';
	while (!ft_strchr(tmp, '\n') && bytes_read == BUFFER_SIZE)
	{
		line = ft_strjoin(line, tmp);
		bytes_read = read(fd, tmp, BUFFER_SIZE);
		if (bytes_read == -1)
			return (buf[0] = '\0', free(line), NULL);
		else if (bytes_read == 0)
			return (buf[0] = '\0', line);
		tmp[bytes_read] = '\0';
	}
	line = ft_strjoin(line, tmp);
	newline_pos = get_newline_pos(line);
	if (ft_strlen(line) > newline_pos)
	{
		ft_memcpy(buf, line + newline_pos + 1, ft_strlen(line + newline_pos));
		line[newline_pos + 1] = '\0';
	}
	else if (ft_strlen(line) == newline_pos)
		buf[0] = '\0';
	return (line);
}
