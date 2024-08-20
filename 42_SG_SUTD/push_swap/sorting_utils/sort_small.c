/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aang-shu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 08:53:55 by aang-shu          #+#    #+#             */
/*   Updated: 2024/04/24 16:37:40 by aang-shu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_size_2(t_stack **a)
{
	t_stack	*current;
	t_stack	*next;

	if ((*a)->rank > ((*a)->next->rank))
		sa(a);
	current = (*a);
	next = current->next;
	free(current);
	free(next);
	*a = NULL;
	exit(EXIT_SUCCESS);
}

static int	find_biggest_node_3(t_stack *stack)
{
	int	i;

	i = 1;
	while (i)
	{
		if (stack->rank == 3)
			break ;
		stack = stack->next;
		i++;
	}	
	return (i);
}

void	sort_size_3(t_stack **a)
{
	int	i;

	i = find_biggest_node_3(*a);
	if (i == 1)
		ra(a);
	else if (i == 2)
		rra(a);
	if ((*a)->rank == 2)
		sa(a);
}

void	sort_size_4(t_stack **a, t_stack **b)
{
	while (get_stack_len(*a) == 4)
	{
		if ((*a)->rank == 4)
			pb(a, b);
		else
			ra(a);
	}
	sort_size_3(a);
	pa(a, b);
	ra(a);
}

void	sort_size_5(t_stack **a, t_stack **b)
{
	if (get_stack_len(*a) == 4)
		sort_size_4(a, b);
	else
	{
		while (get_stack_len(*a) > 3)
		{
			if ((*a)->rank >= 4)
				pb(a, b);
			else
				ra(a);
		}	
		sort_size_3(a);
		if (get_stack_len(*b) == 1)
			pa(a, b);
		else
		{
			if ((*b)->rank == 4)
				rb(b);
			pa(a, b);
			pa(a, b);
			ra(a);
			ra(a);
		}
	}
}
