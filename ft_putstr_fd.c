/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   ft_putstr_fd.c                                    :+:    :+:             */
/*                                                    +:+                     */
/*   By: bvan-den <bvan-den@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2022/10/30 18:53:49 by bvan-den      #+#    #+#                 */
/*   Updated: 2022/10/30 19:24:04 by bvan-den      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}
