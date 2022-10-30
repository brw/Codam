/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   ft_lstlast_bonus.c                                :+:    :+:             */
/*                                                    +:+                     */
/*   By: bvan-den <bvan-den@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2022/10/30 18:53:48 by bvan-den      #+#    #+#                 */
/*   Updated: 2022/10/30 18:53:48 by bvan-den      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}
