/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtanama <rtanama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 00:12:28 by aang-shu          #+#    #+#             */
/*   Updated: 2024/07/14 17:49:29 by rtanama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_numeral(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

static void	handle_numeric_error(char *arg)
{
	char	*str;

	str = ft_strjoin(arg, ": numeric argument required");
	print_error("exit", 0, str);
	free(str);
	g_exit_code = 2;
}

int	execute_exit_cmd(char **args)
{
	long	exit_code;

	if (ft_array_len(args) > 2)
	{
		print_error("exit", 0, "too many arguments");
		return (ERROR);
	}
	if (ft_array_len(args) == 2)
	{
		if (check_numeral(args[1]) == ERROR)
		{
			handle_numeric_error(args[1]);
			return (EXIT);
		}
		exit_code = ft_atol(args[1]);
		exit_code = exit_code % 256;
		g_exit_code = exit_code;
		ft_putendl_fd("exit", STDERR_FILENO);
	}
	return (EXIT);
}
