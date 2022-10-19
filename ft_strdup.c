/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-den <bvan-den@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/19 22:05:31 by bvan-den      #+#    #+#                 */
/*   Updated: 2022/10/19 22:05:35 by bvan-den      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	size_t	s1_len;
	char	*dest;

	s1_len = ft_strlen(s1) + 1;
	dest = malloc(sizeof(char) * s1_len);
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, s1, s1_len);
	return (dest);
}
