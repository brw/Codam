/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   ft_strndup.c                                      :+:    :+:             */
/*                                                    +:+                     */
/*   By: bvan-den <bvan-den@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2022/10/30 18:53:51 by bvan-den      #+#    #+#                 */
/*   Updated: 2022/10/30 18:53:51 by bvan-den      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"
#include <stddef.h>
#include <stdlib.h>

char	*ft_strndup(const char *s1, size_t len)
{
	char	*dest;

	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, s1, len + 1);
	return (dest);
}
