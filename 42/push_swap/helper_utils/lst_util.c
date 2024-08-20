/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aang-shu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 03:29:01 by aang-shu          #+#    #+#             */
/*   Updated: 2024/04/24 08:57:12 by aang-shu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstdelone(t_stack *lst)
{
	if (!lst)
		return ;
	free(&(lst->nbr));
	free(lst);
}

void	ft_lstclear(t_stack **lst)
{
	t_stack	*temp;

	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst);
		*lst = temp;
	}
}

void	lst_push_front(t_stack **lst, int new_nbr)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	new_node->nbr = new_nbr;
	new_node->next = *lst;
	*lst = new_node;
}

void	lst_push_back(t_stack **lst, int new_nbr)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->nbr = new_nbr;
	if (*lst == NULL)
	{
		new_node->next = new_node;
		new_node->prev = new_node;
		*lst = new_node;
	}
	else
	{
		new_node->next = *lst;
		new_node->prev = (*lst)->prev;
		(*lst)->prev->next = new_node;
		(*lst)->prev = new_node;
	}
}
