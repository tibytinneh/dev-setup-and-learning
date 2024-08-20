/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtanama <rtanama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 06:43:39 by aang-shu          #+#    #+#             */
/*   Updated: 2024/07/14 17:36:17 by rtanama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	count_args(char **args)
{
	int	count;

	count = 0;
	while (args[count])
		count++;
	return (count);
}

static int	change_directory(char **args, int arg_count)
{
	int	status;

	if (arg_count == 1)
	{
		if (!getenv("HOME") || chdir(getenv("HOME")) != 0)
		{
			print_error("cd", 0, "HOME not set");
			return (ERROR);
		}
	}
	else if (arg_count > 2)
	{
		print_error("cd", E2BIG, NULL);
		return (ERROR);
	}
	else if (arg_count > 1)
	{
		status = chdir(args[1]);
		if (status != 0)
		{
			print_error("cd", ENOENT, NULL);
			return (ERROR);
		}
	}
	return (SUCCESS);
}

int	execute_cd_cmd(char **args)
{
	int		arg_count;

	arg_count = count_args(args);
	return (change_directory(args, arg_count));
}
