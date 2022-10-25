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
			{
				ft_lstclear(&newlst, del);
				return (NULL);
			}
			currentnode->next = newnode;
			currentnode = newnode;
			lst = lst->next;
		}
	}
	return (newlst);
}
