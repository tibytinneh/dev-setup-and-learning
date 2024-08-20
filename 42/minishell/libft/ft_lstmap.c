/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aang-shu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 08:34:18 by aang-shu          #+#    #+#             */
/*   Updated: 2023/09/10 09:10:41 by aang-shu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	`ft_lstmap` iterates the list `lst`
**	and applies the function `f` on the content of each node.
**	Creates a new list resulting of successive applications of the function `f`
**	The `del` function is used to delete the content if needed
**	
***	`t_list *lst`: the address of a pointer to a node
**	`f`	the address of the function used the iterate on the list
**	`del` the address of the function used to dlt the content of a node if need
**
**	Returns the new list
**	NULL if malloc fail
*/

/*	The function transverses the original list `lst`
**	creates new nodes with the result of applying `f` to the content of each node
**	appends these new nodes to the new list
**	If there's a failure in creating a new node, the function cleans up any node
**	that were successfully created before the failure, then returns NULL
*/

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;

	new_lst = NULL;
	if (!f || !lst)
		return (NULL);
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		if (!new_node)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}
