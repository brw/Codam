/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   ft_toupper.c                                      :+:    :+:             */
/*                                                    +:+                     */
/*   By: bvan-den <bvan-den@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2022/10/30 18:53:51 by bvan-den      #+#    #+#                 */
/*   Updated: 2022/10/30 18:53:51 by bvan-den      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

int	ft_toupper(int c)
{
	if (ft_islower(c))
		return (c - 040);
	return (c);
}
