/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   ft_tolower.c                                      :+:    :+:             */
/*                                                    +:+                     */
/*   By: bvan-den <bvan-den@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2022/10/30 18:53:51 by bvan-den      #+#    #+#                 */
/*   Updated: 2022/10/30 18:53:51 by bvan-den      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_tolower(int c)
{
	if (ft_isupper(c))
		return (c + 040);
	return (c);
}
