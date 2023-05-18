/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   ft_split_args.c                                   :+:    :+:             */
/*                                                    +:+                     */
/*   By: bvan-den <bvan-den@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2022/10/30 18:53:49 by bvan-den      #+#    #+#                 */
/*   Updated: 2023/05/18 16:10:08 by bvan-den      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

static size_t	count_items(char const *s, char delim)
{
	size_t	count;
	char	prev;

	count = 0;
	prev = delim;
	while (*s)
	{
		if (prev == delim && *s != delim)
			count++;
		if (*s == '\'' || *s == '"')
		{
			prev = *s;
			s++;
			while (*s && *s != prev)
				s++;
		}
		prev = *s;
		s++;
	}
	return (count);
}

static size_t	get_item_length(const char **s, char delim)
{
	size_t	i;

	i = 0;
	if (**s == '\'' || **s == '"')
	{
		i++;
		while ((*s)[i] && (*s)[i] != **s)
			i++;
		if ((*s)[i])
			i++;
	}
	else
	{
		while ((*s)[i] && ((*s)[i] != delim || (*s)[i - 1] == '\\'))
		{
			// fprintf(stderr, "%lu - %c - %c\n", i, (*s)[i-1], (*s)[i]);
			i++;
		}
		// fprintf(stderr, "%lu - %c - %c\n", i, (*s)[i-1], (*s)[i]);
	}
	if (((*s)[i - 1] == '\'' && **s == '\'') ||
		((*s)[i - 1] == '"' && **s == '"'))
	{
		(*s)++;
		i -= 2;
	}
	return (i);
}

static void	free_arr(char **arr, size_t index)
{
	while (index != 0)
	{
		free(arr[index - 1]);
		index--;
	}
	free(arr);
}

char	**ft_split_args(char const *str)
{
	char	**arr;
	size_t	count;
	size_t	index;
	size_t	length;

	count = count_items(str, ' ');
	arr = malloc(sizeof(char *) * (count + 1));
	if (!arr)
		return (NULL);
	index = 0;
	while (*str && index < count)
	{
		while (*str == ' ')
			str++;
		length = get_item_length(&str, ' ');
		arr[index] = ft_strndup(str, length);
		if (!arr[index])
			return (free_arr(arr, index), NULL);
		index++;
		str += length;
	}
	arr[index] = NULL;
	return (arr);
}
