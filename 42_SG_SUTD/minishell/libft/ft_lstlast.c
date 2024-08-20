/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aang-shu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 07:16:51 by aang-shu          #+#    #+#             */
/*   Updated: 2023/09/10 07:21:32 by aang-shu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	`ft_lstlast` returns the last node of the LL
**	tranverses the list until it finds a node whose `next` field is NULL
**	AKA last node
**	returns the last node of the LL
*/

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}
