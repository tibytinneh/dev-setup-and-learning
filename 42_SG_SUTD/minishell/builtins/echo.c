/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtanama <rtanama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 10:38:37 by aang-shu          #+#    #+#             */
/*   Updated: 2024/07/03 18:07:35 by rtanama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_n_flag(char *arg)
{
	if (ft_strlen(arg) < 2)
		return (0);
	if (arg[0] == '-' && arg[1] == 'n' && arg[2] == '\0')
		return (1);
	return (0);
}

int	execute_echo_cmd(char **args)
{
	int	i;
	int	has_newline;
	int	is_args;

	i = 1;
	has_newline = 1;
	is_args = 0;
	while (args[i] != NULL)
	{
		if (is_n_flag(args[i]) && !is_args)
		{
			i++;
			has_newline = 0;
			continue ;
		}
		is_args = 1;
		ft_putstr_fd(args[i], 1);
		if (args[i + 1] != NULL)
			ft_putstr_fd(" ", 1);
		i ++;
	}
	if (has_newline)
		ft_putstr_fd("\n", 1);
	return (SUCCESS);
}
