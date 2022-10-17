/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-den <bvan-den@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/17 20:58:47 by bvan-den      #+#    #+#                 */
/*   Updated: 2022/10/17 20:58:48 by bvan-den      ########   odam.nl         */
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
