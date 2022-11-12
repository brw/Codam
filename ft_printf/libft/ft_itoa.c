/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   ft_itoa.c                                         :+:    :+:             */
/*                                                    +:+                     */
/*   By: bvan-den <bvan-den@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2022/10/30 18:53:47 by bvan-den      #+#    #+#                 */
/*   Updated: 2022/10/30 18:53:47 by bvan-den      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"
#include <limits.h>
#include <stddef.h>
#include <stdlib.h>

static size_t	get_length(int n)
{
	size_t	length;

	length = 0;
	if (n <= 0)
		length++;
	while (n != 0)
	{
		n /= 10;
		length++;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	num;
	size_t			length;

	length = get_length(n);
	str = malloc(sizeof(char) * (length + 1));
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		num = (unsigned int)(n * -1);
		str[0] = '-';
	}
	else
		num = (unsigned int)n;
	str[length] = '\0';
	while (num > 0)
	{
		str[length - 1] = num % 10 + '0';
		num /= 10;
		length--;
	}
	return (str);
}
