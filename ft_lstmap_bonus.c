/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-den <bvan-den@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/27 20:15:22 by bvan-den      #+#    #+#                 */
/*   Updated: 2022/10/28 22:06:44 by bvan-den      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*create_node(char *content, void (*del)(void *))
{
	t_list	*newlst;

	newlst = ft_lstnew(content);
	if (!newlst)
		del(content);
	return (newlst);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*currentnode;
	t_list	*newnode;

	if (!lst)
		return (NULL);
	currentnode = create_node(f(lst->content), del);
	if (!currentnode)
		return (NULL);
	newlst = currentnode;
	lst = lst->next;
	while (lst)
	{
		newnode = create_node(f(lst->content), del);
		if (!newnode)
		{
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		currentnode->next = newnode;
		currentnode = newnode;
		lst = lst->next;
	}
	return (newlst);
}
