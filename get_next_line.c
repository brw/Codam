#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 10

size_t	get_newline_pos(const char *s)
{
	size_t	i;

	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*str;

	if (!s1)
		s1 = "";
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

// char	*add_to_buf(char *buf, char *content)
// {
// 	size_t	buf_len;
// 	size_t	content_len;
// 	size_t	i;
// 	char	*str;
//
// 	buf_len = ft_strlen(buf);
// 	content_len = ft_strlen(content);
// 	str = malloc(sizeof(char) * (buf_len + content_len + 1));
// 	if (!str)
// 		return (NULL);
// 	i = 0;
// 	while (i < buf_len + content_len)
// 	{
// 		if (i < buf_len)
// 			((unsigned char *)str)[i] = ((unsigned char *)buf)[i];
// 		else
// 			((unsigned char *)str)[i] = ((unsigned char *)content)[i - buf_len];
// 		i++;
// 	}
// 	str[i] = '\0';
// 	free(buf);
// 	return (str);
// }

char	*get_line(char **buf, int fd)
{
	char	*str;
	char	*tmp;
	size_t	newline_pos;
	ssize_t	written;
	written = read(fd, tmp, BUFFER_SIZE);
	while (written != -1)
	{
		*buf = ft_strjoin(*buf, tmp);
		newline_pos = get_newline_pos(*buf);
		if (newline_pos)
			break;
		written = read(fd, tmp, BUFFER_SIZE);
	}
	str = ft_strndup(*buf, newline_pos);
	*buf = *buf + newline_pos;
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;

	buf = NULL;
	line = get_line(&buf, fd);
	return (line);
}
