/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   get_next_line_bonus.h                             :+:    :+:             */
/*                                                    +:+                     */
/*   By: bvan-den <bvan-den@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2023/01/29 04:24:59 by bvan-den      #+#    #+#                 */
/*   Updated: 2023/06/02 01:50:28 by bvan-den      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stddef.h>

# ifdef linux
#  define OPEN_MAX 256
# endif

char	*get_next_line(int fd);
size_t	gnl_strlen(const char *s);
void	*gnl_memcpy(void *dst, const void *src, size_t n);
size_t	gnl_strlcat(char *dst, const char *src, size_t dstsize);
size_t	gnl_strlcpy(char *dst, const char *src, size_t dstsize);
char	*gnl_strchr(const char *s, int c);

#endif
