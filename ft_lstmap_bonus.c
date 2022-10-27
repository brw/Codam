/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-den <bvan-den@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/27 20:15:22 by bvan-den      #+#    #+#                 */
/*   Updated: 2022/10/27 20:22:09 by bvan-den      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*currentnode;
	t_list	*newnode;

	newlst = NULL;
	if (lst)
	{
		newlst = ft_lstnew(f(lst->content));
		if (!newlst)
			return (NULL);
		currentnode = newlst;
		lst = lst->next;
		while (lst)
		{
			newnode = ft_lstnew(f(lst->content));
			if (!newnode)
				return (ft_lstclear(&newlst, del), NULL);
			currentnode->next = newnode;
			currentnode = newnode;
			lst = lst->next;
		}
	}
	return (newlst);
}
