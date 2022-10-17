/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-den <bvan-den@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 15:53:28 by bvan-den      #+#    #+#                 */
/*   Updated: 2022/10/07 18:18:40 by bvan-den      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char		ch;
	const char	*res;

	ch = (char)c;
	if (ch == '\0')
		return (ft_strchr(s, '\0'));
	res = NULL;
	while (*s)
	{
		if (*s == ch)
			res = s;
		s++;
	}
	return ((char *)(res));
}
