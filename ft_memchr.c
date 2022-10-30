/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   ft_memchr.c                                       :+:    :+:             */
/*                                                    +:+                     */
/*   By: bvan-den <bvan-den@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2022/10/30 18:53:48 by bvan-den      #+#    #+#                 */
/*   Updated: 2022/10/30 18:53:48 by bvan-den      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;

	if (n == 0)
		return (0);
	str = (unsigned char *)s;
	while (*str != (unsigned char)c)
	{
		n--;
		if (n == 0)
			return (0);
		str++;
	}
	return (str);
}
