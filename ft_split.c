/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   ft_split.c                                        :+:    :+:             */
/*                                                    +:+                     */
/*   By: bvan-den <bvan-den@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2022/10/30 18:53:49 by bvan-den      #+#    #+#                 */
/*   Updated: 2022/11/02 22:35:14 by bvan-den      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

static size_t	count_items(char const *s, char delim)
{
	size_t	count;
	size_t	i;
	char	prev;

	count = 0;
	i = 0;
	prev = delim;
	while (s[i])
	{
		if (prev == delim && s[i] != delim)
			count++;
		prev = s[i];
		i++;
	}
	return (count);
}

static size_t	get_item_length(const char *s, char delim)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != delim)
		i++;
	return (i);
}

static void	free_arr(char **arr, size_t index)
{
	size_t	i;

	i = 0;
	while (i < index)
		free(arr[i++]);
	free(arr);
}

char	**ft_split(char const *str, char delim)
{
	char	**arr;
	size_t	count;
	size_t	index;
	size_t	length;

	count = count_items(str, delim);
	arr = malloc(sizeof(char *) * (count + 1));
	if (!arr)
		return (NULL);
	index = 0;
	while (*str && index < count)
	{
		while (*str == delim)
			str++;
		length = get_item_length(str, delim);
		arr[index] = ft_strndup(str, length);
		if (!arr[index])
			return (free_arr(arr, index), NULL);
		index++;
		str += length;
	}
	arr[index] = NULL;
	return (arr);
}
