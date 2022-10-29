/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-den <bvan-den@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/17 19:33:25 by bvan-den      #+#    #+#                 */
/*   Updated: 2022/10/29 19:57:26 by bvan-den      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dest;
	unsigned char	*source;

	if (!dst && !src)
		return (NULL);
	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	if (dest < source)
		ft_memcpy(dest, source, len);
	else
	{
		while (len > 0)
		{
			dest[len - 1] = source[len - 1];
			len--;
		}
	}
	return (dst);
}
