/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aang-shu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:21:17 by aang-shu          #+#    #+#             */
/*   Updated: 2024/04/24 10:22:40 by aang-shu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_stack	*current;

	if (stack == NULL)
		return (1);
	current = stack;
	while (current->next != stack)
	{
		if (current->rank > current->next->rank)
			return (0);
		current = current->next;
	}
	return (1);
}
