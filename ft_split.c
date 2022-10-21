#include "libft.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

size_t	count_items(char const *s, char delim)
{
	size_t	count;

	count = 1;
	while (*s)
		if (*s++ == delim)
			count++;
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	left;
	size_t	right;
	size_t	index;

	left = 0;
	right = 0;
	index = 0;
	s = ft_strtrim(s, &c);
	arr = malloc(sizeof(char *) * count_items(s, c) + 1);
	if (!arr)
		return (NULL);
	while (s[right])
	{
		while (s[left] && s[left] == c)
			left++;
		right = left + 1;
		while(s[right] && s[right] != c)
			right++;
		arr[index] = malloc(sizeof(char) * (right - left + 1));
		if (!arr[index])
			return (NULL);
		ft_strlcpy(arr[index], s + left, right - left + 1);
		index++;
		left = right + 1;
	}
	arr[index] = NULL;
	return (arr);
}
