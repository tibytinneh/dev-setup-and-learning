/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aang-shu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 22:42:51 by aang-shu          #+#    #+#             */
/*   Updated: 2023/09/10 07:05:59 by aang-shu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	`ft_lstnew` creates a new element of type t_list
**	Returns the new node. Else `NULL`
**
**	declare t_list *new -> malloc -> malloc fail check
**	-> init *(new.content) with void *content -> next pointer NULL
**	-> return new
*/

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
