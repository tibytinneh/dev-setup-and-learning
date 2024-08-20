/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aang-shu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 07:26:45 by aang-shu          #+#    #+#             */
/*   Updated: 2023/09/10 07:33:39 by aang-shu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	`ft_lstadd_back` adds the node `new` at the end of the list
**
**	t_list last (to be assigned the last node)
**	if *lst == NULL, assign new to *lst
**	ELSE
**	uses the `ft_lstlast` to find the LAST NODE in the list
**	then point its next field to the new node.
*/

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (*lst == NULL)
		*lst = new;
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
}
