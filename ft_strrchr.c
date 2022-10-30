/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-den <bvan-den@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 15:53:28 by bvan-den      #+#    #+#                 */
/*   Updated: 2022/10/30 12:47:47 by bvan-den      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	ch;
	char	*res;

	ch = (char)c;
	if (ch == '\0')
		return (ft_strchr(s, '\0'));
	res = NULL;
	while (*s)
	{
		if (*s == ch)
			res = (char *)s;
		s++;
	}
	return (res);
}
