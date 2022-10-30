/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   ft_memcmp.c                                       :+:    :+:             */
/*                                                    +:+                     */
/*   By: bvan-den <bvan-den@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2022/10/30 18:53:48 by bvan-den      #+#    #+#                 */
/*   Updated: 2022/10/30 20:51:30 by bvan-den      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (((unsigned char *)s1)[i] == ((unsigned char *)s2)[i] && i < n - 1)
		i++;
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}
