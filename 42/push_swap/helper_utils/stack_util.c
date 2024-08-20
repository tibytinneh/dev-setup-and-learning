/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aang-shu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 03:32:48 by aang-shu          #+#    #+#             */
/*   Updated: 2024/04/24 16:15:42 by aang-shu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	init_stack_rank(t_stack **stack)
{
	rank_nodes(*stack);
	return (get_stack_len(*stack));
}

void	free_stack(t_stack **a)
{
	t_stack	*current;
	t_stack	*next;

	if (*a == NULL)
		return ;
	current = (*a)->next;
	while (current != *a)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(*a);
	*a = NULL;
}

int	get_stack_len(t_stack *stack)
{
	int		count;
	t_stack	*current;

	if (!stack)
		return (0);
	count = 1;
	current = stack->next;
	while (current != stack)
	{
		current = current->next;
		count++;
	}
	return (count);
}

void	rank_nodes(t_stack *stack)
{
	t_stack	*node;
	t_stack	*temp;
	int		rank;

	if (stack == NULL)
		return ;
	node = stack;
	while (node)
	{
		rank = 1;
		temp = node->next;
		while (temp != node)
		{
			if (node->nbr > temp->nbr)
				rank++;
			temp = temp->next;
		}
		node->rank = rank;
		node = node->next;
		if (node == stack)
			break ;
	}
}

void	ft_print_stack(t_stack *lst)
{
	t_stack	*start;

	start = lst;
	if (lst == NULL)
		return ;
	ft_putnbr(lst->nbr);
	lst = lst->next;
	while (lst != start)
	{
		write(1, " ", 1);
		ft_putnbr(lst->nbr);
		lst = lst->next;
	}
}
