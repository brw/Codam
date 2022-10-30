/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   ft_memset.c                                       :+:    :+:             */
/*                                                    +:+                     */
/*   By: bvan-den <bvan-den@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2022/10/30 18:53:49 by bvan-den      #+#    #+#                 */
/*   Updated: 2022/10/30 18:53:49 by bvan-den      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*s;

	s = (unsigned char *)b;
	while (len > 0)
	{
		*s = (unsigned char)c;
		s++;
		len--;
	}
	return (b);
}
