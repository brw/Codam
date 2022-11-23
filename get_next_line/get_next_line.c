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
	if (!s[i])
		return (BUFFER_SIZE + 1);
	return (i);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	int		should_free;
	char	*str;

	should_free = 1;
	if (!s1)
	{
		s1 = "";
		should_free = 0;
	}
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, s1_len + 1);
	ft_strlcat(str, s2, s1_len + s2_len + 1);
	if (should_free)
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

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (dst == src)
		return (dst);
	if (dst < src)
		ft_memcpy(dst, src, len);
	else
	{
		while (len > 0)
		{
			((unsigned char *)dst)[len - 1] = ((unsigned char *)src)[len - 1];
			len--;
		}
	}
	return (dst);
}

char	*get_next_line(int fd)
{
	static char	leftover[BUFFER_SIZE + 1];
	char		*str;
	char		tmp[BUFFER_SIZE + 1];
	size_t		newline_pos;
	ssize_t		bytes_read;

	str = NULL;
	if (ft_strchr(leftover, '\n'))
	{
		newline_pos = get_newline_pos(leftover);
		str = ft_strndup(leftover, newline_pos + 1);
		ft_strlcpy(leftover, leftover + newline_pos + 1, ft_strlen(leftover
					+ newline_pos) + 1);
		return (str);
	}
	else
		str = ft_strjoin(str, leftover);
	bytes_read = read(fd, tmp, BUFFER_SIZE);
	if (bytes_read == -1)
	{
		free(str);
		return (NULL);
	}
	tmp[bytes_read] = '\0';
	while (get_newline_pos(tmp) == BUFFER_SIZE + 1 && bytes_read != 0)
	{
		str = ft_strjoin(str, tmp);
		bytes_read = read(fd, tmp, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(str);
			return (NULL);
		}
		tmp[bytes_read] = '\0';
	}
	if (bytes_read == 0)
		return (NULL);
	str = ft_strjoin(str, tmp);
	newline_pos = get_newline_pos(str);
	ft_memcpy(leftover, str + newline_pos + 1, ft_strlen(str + newline_pos));
	str[newline_pos + 1] = '\0';
	return (str);
}
