/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   ft_strchr.c                                       :+:    :+:             */
/*                                                    +:+                     */
/*   By: bvan-den <bvan-den@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2022/10/30 18:53:50 by bvan-den      #+#    #+#                 */
/*   Updated: 2022/10/30 20:15:45 by bvan-den      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
	{
		if (*s == '\0')
			return (0);
		s++;
	}
	return ((char *)(s));
}
