/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-den <bvan-den@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/23 00:31:02 by bvan-den      #+#    #+#                 */
/*   Updated: 2022/10/23 00:31:05 by bvan-den      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

static size_t	count_items(char const *s, char delim)
{
	size_t	count;
	size_t	i;
	char	last;

	count = 0;
	i = 0;
	last = delim;
	while (s[i])
	{
		if (last == delim && s[i] != delim)
			count++;
		last = s[i];
		i++;
	}
	return (count);
}

static void	free_arr(char **arr, size_t index)
{
	size_t	i;

	i = 0;
	while (i < index)
		free(arr[i++]);
	free(arr);
}

static size_t	get_item_length(const char *s, char delim)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != delim)
		i++;
	return (i);
}

static void	*malloc_or_free(char **arr, const char *str, size_t index,
		size_t length)
{
	arr[index] = ft_strndup(str, length);
	if (!arr[index])
	{
		free_arr(arr, index);
		return (NULL);
	}
	return (arr[index]);
}

char	**ft_split(char const *str, char delim)
{
	char	**arr;
	size_t	count;
	size_t	length;
	size_t	index;

	if (!str)
		return (NULL);
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
		arr[index] = malloc_or_free(arr, str, index, length);
		if (!arr[index])
			return (NULL);
		index++;
		str += length;
	}
	arr[index] = NULL;
	return (arr);
}
