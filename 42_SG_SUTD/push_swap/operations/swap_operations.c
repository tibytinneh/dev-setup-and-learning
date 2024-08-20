/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aang-shu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 07:27:34 by aang-shu          #+#    #+#             */
/*   Updated: 2024/04/24 08:59:58 by aang-shu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_two_nodes(t_stack **head)
{
	t_stack	*first;
	t_stack	*second;

	first = *head;
	second = first->next;
	first->next = second->next;
	second->prev = first->prev;
	first->prev = second;
	second->next = first;
	*head = second;
}

void	swap_more_than_two_nodes(t_stack **head)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*temp;

	first = *head;
	second = first->next;
	first->prev->next = second;
	second->next->prev = first;
	first->next = second->next;
	second->next = first;
	temp = first->prev;
	second->prev = temp;
	*head = second;
}

void	swap(t_stack **head)
{
	if (!head || !(*head) || !(*head)->next)
		return ;
	if ((*head)->next->next == *head)
		swap_two_nodes(head);
	else
		swap_more_than_two_nodes(head);
}
