/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   ft_bzero.c                                        :+:    :+:             */
/*                                                    +:+                     */
/*   By: bvan-den <bvan-den@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2022/10/30 18:53:46 by bvan-den      #+#    #+#                 */
/*   Updated: 2022/10/30 18:53:46 by bvan-den      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"
#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
