/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aang-shu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 08:07:52 by aang-shu          #+#    #+#             */
/*   Updated: 2024/04/24 09:00:25 by aang-shu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_stack	**head)
{
	if (head == NULL || *head == NULL || (*head)->next == *head)
		return ;
	*head = (*head)->next;
}

void	reverse_rotate(t_stack **head)
{
	if (head == NULL || *head == NULL || (*head)->next == *head)
		return ;
	*head = (*head)->prev;
}
