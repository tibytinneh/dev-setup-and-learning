/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aang-shu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:25:47 by aang-shu          #+#    #+#             */
/*   Updated: 2024/04/24 16:35:57 by aang-shu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	nuke_b_back(t_stack **a, t_stack **b)
{
	int	b_len;

	b_len = get_stack_len(*b);
	while (b_len > 0)
	{
		pa(a, b);
		b_len--;
	}
}

void	radix_sort(t_stack **a, t_stack **b, int bits_num)
{
	int	a_len;
	int	right_shift;
	int	bits_processed;

	right_shift = 0;
	while (right_shift < bits_num)
	{
		a_len = get_stack_len(*a);
		bits_processed = 0;
		while (bits_processed < a_len)
		{
			if (((*a)->rank >> right_shift) & 1)
				ra(a);
			else
				pb(a, b);
			bits_processed++;
		}
		nuke_b_back(a, b);
		right_shift++;
	}
}
