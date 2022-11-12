/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   ft_isalnum.c                                      :+:    :+:             */
/*                                                    +:+                     */
/*   By: bvan-den <bvan-den@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2022/10/30 18:53:46 by bvan-den      #+#    #+#                 */
/*   Updated: 2022/10/30 18:53:46 by bvan-den      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
