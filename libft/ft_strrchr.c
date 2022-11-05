/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   ft_strrchr.c                                      :+:    :+:             */
/*                                                    +:+                     */
/*   By: bvan-den <bvan-den@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2022/10/30 18:53:51 by bvan-den      #+#    #+#                 */
/*   Updated: 2022/10/30 20:14:35 by bvan-den      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*res;

	if ((char)c == '\0')
		return (ft_strchr(s, '\0'));
	res = NULL;
	while (*s)
	{
		if (*s == (char)c)
			res = (char *)s;
		s++;
	}
	return (res);
}
