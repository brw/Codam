/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   ft_lstdelone_bonus.c                              :+:    :+:             */
/*                                                    +:+                     */
/*   By: bvan-den <bvan-den@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2022/10/30 18:53:48 by bvan-den      #+#    #+#                 */
/*   Updated: 2022/10/31 18:10:11 by bvan-den      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	del(lst->content);
	free(lst);
}
