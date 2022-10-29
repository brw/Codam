/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-den <bvan-den@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/19 22:05:31 by bvan-den      #+#    #+#                 */
/*   Updated: 2022/10/29 19:10:22 by bvan-den      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	size_t	s1_len;
	char	*dest;

	s1_len = ft_strlen(s1);
	dest = malloc(sizeof(char) * (s1_len + 1));
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, s1, s1_len + 1);
	return (dest);
}
