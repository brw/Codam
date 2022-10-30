/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   ft_strtrim.c                                      :+:    :+:             */
/*                                                    +:+                     */
/*   By: bvan-den <bvan-den@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2022/10/30 18:53:51 by bvan-den      #+#    #+#                 */
/*   Updated: 2022/10/30 18:53:51 by bvan-den      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

static int	in_set(char c, char const *set)
{
	while (*set)
	{
		if (c == (char)*set++)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	left;
	size_t	right;
	char	*dest;

	if (!s1)
		return (NULL);
	left = 0;
	right = ft_strlen(s1);
	while (in_set(s1[left], set))
		left++;
	if (s1[left] == '\0')
		return (ft_strdup(""));
	while (in_set(s1[right - 1], set))
		right--;
	dest = malloc(sizeof(char) * (right - left + 1));
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, s1 + left, right - left + 1);
	return (dest);
}
