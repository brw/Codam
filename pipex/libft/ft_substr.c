/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   ft_substr.c                                       :+:    :+:             */
/*                                                    +:+                     */
/*   By: bvan-den <bvan-den@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2022/10/30 18:53:51 by bvan-den      #+#    #+#                 */
/*   Updated: 2022/10/31 18:08:50 by bvan-den      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stddef.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	length;

	length = ft_strlen(s);
	if (start > length)
		return (ft_strdup(""));
	if (start + len > length)
		substr = ft_strdup(s + start);
	else
		substr = ft_strndup(s + start, len);
	if (!substr)
		return (NULL);
	return (substr);
}
