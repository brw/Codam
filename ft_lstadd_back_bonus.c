/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   ft_lstadd_back_bonus.c                            :+:    :+:             */
/*                                                    +:+                     */
/*   By: bvan-den <bvan-den@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2022/10/30 18:53:47 by bvan-den      #+#    #+#                 */
/*   Updated: 2022/10/30 18:53:47 by bvan-den      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	last = ft_lstlast(*lst);
	if (!last)
		*lst = new;
	else
		last->next = new;
}
