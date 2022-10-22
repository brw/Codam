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

void	free_arr(char **arr, size_t index)
{
	size_t	i;

	i = 0;
	while (i < index)
		free(arr[i++]);
	free(arr);
}

size_t	get_item_length(const char *s, char delim)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != delim)
		i++;
	return (i);
}

char	**ft_split(char const *str, char delim)
{
	char	**arr;
	size_t	count;
	size_t	length;
	size_t	index;

	index = 0;
	count = count_items(str, delim);
	arr = malloc(sizeof(char *) * (count + 1));
	if (!arr)
		return (NULL);
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
