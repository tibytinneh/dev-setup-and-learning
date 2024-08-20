/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aang-shu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 06:32:25 by aang-shu          #+#    #+#             */
/*   Updated: 2024/04/24 06:11:49 by aang-shu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_handler(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void	error_handler_free_stack(t_stack **stack)
{
	free_stack(stack);
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

int	input_check(char *arg)
{
	if (*arg == '-' || *arg == '+')
		arg++;
	if (!(*arg >= '0' && *arg <= '9'))
		return (-1);
	while (*arg)
	{
		if (!(*arg >= '0' && *arg <= '9'))
			return (-1);
		arg++;
	}
	return (1);
}

int	duplicate_check(t_stack *a)
{
	t_stack	*start;
	t_stack	*current;
	t_stack	*runner;

	if (a == NULL || a->next == a)
		return (0);
	start = a;
	current = a;
	while (current != NULL && current->next != start)
	{
		runner = current->next;
		while (runner != start)
		{
			if (current->nbr == runner->nbr)
				return (1);
			runner = runner->next;
		}
		current = current->next;
		if (current == start)
			break ;
	}
	return (0);
}
