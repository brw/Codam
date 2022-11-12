/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   ft_putendl_fd.c                                   :+:    :+:             */
/*                                                    +:+                     */
/*   By: bvan-den <bvan-den@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2022/10/30 18:53:49 by bvan-den      #+#    #+#                 */
/*   Updated: 2022/10/30 18:53:49 by bvan-den      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"
#include <unistd.h>

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
}
