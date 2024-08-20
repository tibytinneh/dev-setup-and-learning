/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aang-shu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 17:30:27 by aang-shu          #+#    #+#             */
/*   Updated: 2024/04/24 16:13:12 by aang-shu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		count;
	int		bits_num;

	a = init_pushswap(ac, av);
	b = NULL;
	if (duplicate_check(a))
		error_handler_free_stack(&a);
	count = init_stack_rank(&a);
	bits_num = number_of_bits(count);
	if (!is_sorted(a))
	{
		if (count == 2)
			sort_size_2(&a);
		else if (count == 3)
			sort_size_3(&a);
		else if (count <= 5)
			sort_size_5(&a, &b);
		else
			radix_sort(&a, &b, bits_num);
	}
	free_stack(&a);
	free_stack(&b);
	return (0);
}
