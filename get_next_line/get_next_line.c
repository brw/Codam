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

char	*ft_strjoin(char *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*str;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, s1_len + 1);
	ft_strlcat(str, s2, s1_len + s2_len + 1);
	free(s1);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	leftover[BUFFER_SIZE + 1];
	char		*line;
	char		tmp[BUFFER_SIZE + 1];
	size_t		newline_pos;
	ssize_t		bytes_read;

	if (ft_strchr(leftover, '\n'))
	{
		newline_pos = get_newline_pos(leftover);
		line = ft_strndup(leftover, newline_pos + 1);
		ft_memcpy(leftover, leftover + newline_pos + 1, ft_strlen(leftover
					+ newline_pos) + 1);
		return (line);
	}
	line = ft_strndup(leftover, ft_strlen(leftover));
	bytes_read = read(fd, tmp, BUFFER_SIZE);
	if (bytes_read == -1)
		return (leftover[0] = '\0', free(line), NULL);
	else if (bytes_read == 0 && ft_strlen(line) > 0)
		return (leftover[0] = '\0', line);
	else if (bytes_read == 0)
		return (leftover[0] = '\0', free(line), NULL);
	tmp[bytes_read] = '\0';
	while (!ft_strchr(tmp, '\n') && bytes_read == BUFFER_SIZE)
	{
		line = ft_strjoin(line, tmp);
		bytes_read = read(fd, tmp, BUFFER_SIZE);
		if (bytes_read == -1)
			return (leftover[0] = '\0', free(line), NULL);
		else if (bytes_read == 0)
			return (leftover[0] = '\0', line);
		tmp[bytes_read] = '\0';
	}
	line = ft_strjoin(line, tmp);
	newline_pos = get_newline_pos(line);
	if (ft_strlen(line) > newline_pos)
	{
		ft_memcpy(leftover, line + newline_pos + 1, ft_strlen(line
					+ newline_pos));
		line[newline_pos + 1] = '\0';
	}
	else if (ft_strlen(line) == newline_pos)
		leftover[0] = '\0';
	return (line);
}
