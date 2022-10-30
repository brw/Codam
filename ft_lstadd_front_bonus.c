/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   ft_lstadd_front_bonus.c                           :+:    :+:             */
/*                                                    +:+                     */
/*   By: bvan-den <bvan-den@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2022/10/30 18:53:47 by bvan-den      #+#    #+#                 */
/*   Updated: 2022/10/30 18:53:47 by bvan-den      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
