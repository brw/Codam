/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   get_next_line_utils_bonus.c                       :+:    :+:             */
/*                                                    +:+                     */
/*   By: bvan-den <bvan-den@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/01/29 04:25:10 by bvan-den      #+#    #+#                 */
/*   Updated: 2023/05/31 22:27:47 by bvan-den      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	gnl_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*gnl_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (dst == src)
		return (dst);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

size_t	gnl_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (dstsize == 0)
		return (gnl_strlen(src));
	i = 0;
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (gnl_strlen(src));
}

size_t	gnl_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;

	dstlen = gnl_strlen(dst);
	if (dstsize != 0 && dstlen < dstsize)
		gnl_strlcpy(dst + dstlen, src, dstsize - dstlen);
	else
		return (dstsize + gnl_strlen(src));
	return (dstlen + gnl_strlen(src));
}

char	*gnl_strchr(const char *s, int c)
{
	while (*s != (char)c)
	{
		if (*s == '\0')
			return (0);
		s++;
	}
	return ((char *)(s));
}
