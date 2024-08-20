/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_detach_attach_node.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aang-shu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 08:06:32 by aang-shu          #+#    #+#             */
/*   Updated: 2024/04/18 08:06:47 by aang-shu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	detach_node(t_stack **head, t_stack *node)
{
	if (*head == NULL || node == NULL)
		return ;
	if (node->next == node)
		*head = NULL;
	else
	{
		node->next->prev = node->prev;
		node->prev->next = node->next;
		if (*head == node)
			*head = node->next;
	}
}

void	attach_node(t_stack **head, t_stack *node)
{
	if (*head == NULL)
	{
		*head = node;
		node->next = node;
		node->prev = node;
	}
	else
	{
		node->next = *head;
		node->prev = (*head)->prev;
		(*head)->prev->next = node;
		(*head)->prev = node;
		*head = node;
	}
}

void	push_node(t_stack **dest, t_stack **src)
{
	t_stack	*source;

	if (src == NULL || *src == NULL)
		return ;
	source = *src;
	detach_node(src, source);
	attach_node(dest, source);
}
