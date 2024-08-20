/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aang-shu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 08:28:06 by aang-shu          #+#    #+#             */
/*   Updated: 2024/05/06 14:44:28 by aang-shu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	nbr_check_1(long nbr, char **nbr_args, t_stack *a)
{
	if (nbr > 2147483647 || nbr < -2147483648)
	{
		ft_free(nbr_args);
		free_stack(&a);
		error_handler_free_stack(&a);
	}
}

static void	nbr_check_2(long nbr, char *nbr_arg, t_stack *a)
{
	if (nbr > 2147483647 || nbr < -2147483648)
	{
		free(nbr_arg);
		free_stack(&a);
		error_handler_free_stack(&a);
	}
}

t_stack	*init_stack_1(char *args)
{
	t_stack	*a;
	char	**nbr_args;
	int		i;
	long	nbr;

	a = NULL;
	nbr_args = ft_split(args, ' ');
	i = 0;
	while (nbr_args[i])
	{
		if (input_check(nbr_args[i]) == -1)
		{
			ft_free(nbr_args);
			error_handler_free_stack(&a);
		}
		nbr = ft_atoi(nbr_args[i]);
		nbr_check_1(nbr, nbr_args, a);
		lst_push_back(&a, nbr);
		i++;
	}
	ft_free(nbr_args);
	return (a);
}

t_stack	*init_stack_2(int ac, char **av)
{
	t_stack	*a;
	char	*nbr_arg;
	int		i;
	long	nbr;

	a = NULL;
	i = 1;
	while (i < ac)
	{
		nbr_arg = ft_strdup(av[i]);
		if (nbr_arg == NULL)
			error_handler_free_stack(&a);
		if (input_check(nbr_arg) == -1)
		{
			free(nbr_arg);
			error_handler_free_stack(&a);
		}
		nbr = ft_atoi(nbr_arg);
		nbr_check_2(nbr, nbr_arg, a);
		lst_push_back(&a, nbr);
		free(nbr_arg);
		i++;
	}
	return (a);
}

t_stack	*init_pushswap(int ac, char **av)
{
	t_stack	*a;

	if (ac < 2)
		exit(EXIT_FAILURE);
	if (ac == 2)
		a = init_stack_1(av[1]);
	else
		a = init_stack_2(ac, av);
	return (a);
}
