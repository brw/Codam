/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-den <bvan-den@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/23 00:31:02 by bvan-den      #+#    #+#                 */
/*   Updated: 2022/10/27 21:05:02 by bvan-den      ########   odam.nl         */
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

static char	**split_str(char **arr, char const *str, char delim, size_t count)
{
	size_t	index;
	size_t	length;

	index = 0;
	while (*str && index < count)
	{
		while (*str == delim)
			str++;
		length = get_item_length(str, delim);
		arr[index] = ft_strndup(str, length);
		if (!arr[index])
		{
			free_arr(arr, index);
			return (NULL);
		}
		index++;
		str += length;
	}
	arr[index] = NULL;
	return (arr);
}

char	**ft_split(char const *str, char delim)
{
	char	**arr;
	size_t	count;

	if (!str)
		return (NULL);
	count = count_items(str, delim);
	arr = malloc(sizeof(char *) * (count + 1));
	if (!arr)
		return (NULL);
	arr = split_str(arr, str, delim, count);
	return (arr);
}
