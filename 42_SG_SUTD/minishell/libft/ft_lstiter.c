/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aang-shu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 08:29:00 by aang-shu          #+#    #+#             */
/*   Updated: 2023/09/10 08:33:54 by aang-shu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	`ft_lstiter` iterates the LL `lst` and applies the function `f` on the
**	content of each node
**
**	`t_list *lst`: the address of a pointer to a node
**	`f`	the address of the function used the iterate on the list
**
**	basically strmapi but different things
**	while there's still nodes, apply the function on the content of the LL node
**	navigate to the next node
**	exit while loop when there's no more nodes
*/

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
