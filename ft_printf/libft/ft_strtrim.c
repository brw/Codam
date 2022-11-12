/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   ft_strtrim.c                                      :+:    :+:             */
/*                                                    +:+                     */
/*   By: bvan-den <bvan-den@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2022/10/30 18:53:51 by bvan-den      #+#    #+#                 */
/*   Updated: 2022/10/30 20:36:57 by bvan-den      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"
#include <stddef.h>
#include <stdlib.h>

static int	in_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	left;
	size_t	right;

	left = 0;
	right = ft_strlen(s1);
	while (in_set(s1[left], set))
		left++;
	if (s1[left] == '\0')
		return (ft_strdup(""));
	while (in_set(s1[right - 1], set))
		right--;
	return (ft_strndup(s1 + left, right - left));
}
