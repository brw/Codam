/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-den <bvan-den@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/17 19:33:25 by bvan-den      #+#    #+#                 */
/*   Updated: 2022/10/17 19:33:27 by bvan-den      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dest;
	unsigned char	*source;
	size_t			i;

	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	i = 0;
	if (dest < source)
		while (len > 0)
		{
			dest[i] = source[i];
			i++;
			len--;
		}
	else
		while (i < len)
		{
			dest[len - i - 1] = source[len - i - 1];
			i++;
		}
	return (dst);
}
