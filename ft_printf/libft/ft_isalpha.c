/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   ft_isalpha.c                                      :+:    :+:             */
/*                                                    +:+                     */
/*   By: bvan-den <bvan-den@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2022/10/30 18:53:47 by bvan-den      #+#    #+#                 */
/*   Updated: 2022/10/30 18:53:47 by bvan-den      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

int	ft_isalpha(int c)
{
	return (ft_isupper(c) || ft_islower(c));
}
