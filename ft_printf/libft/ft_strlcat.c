/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   ft_strlcat.c                                      :+:    :+:             */
/*                                                    +:+                     */
/*   By: bvan-den <bvan-den@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2022/10/30 18:53:50 by bvan-den      #+#    #+#                 */
/*   Updated: 2022/10/30 18:53:50 by bvan-den      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"
#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;

	dstlen = ft_strlen(dst);
	if (dstsize != 0 && dstlen < dstsize)
		ft_strlcpy(dst + dstlen, src, dstsize - dstlen);
	else
		return (dstsize + ft_strlen(src));
	return (dstlen + ft_strlen(src));
}
