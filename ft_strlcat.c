/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-den <bvan-den@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/17 20:58:24 by bvan-den      #+#    #+#                 */
/*   Updated: 2022/10/23 21:37:13 by bvan-den      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;

	dstlen = ft_strlen(dst);
	if (dstsize != 0 && dstsize > dstlen)
		ft_strlcpy(dst + dstlen, src, dstsize - dstlen);
	else
		return (dstsize + ft_strlen(src));
	return (dstlen + ft_strlen(src));
}
