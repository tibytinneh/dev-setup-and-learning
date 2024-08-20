/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtanama <rtanama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 04:25:21 by aang-shu          #+#    #+#             */
/*   Updated: 2024/07/13 03:53:25 by rtanama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_valid_var(char *arg)
{
	size_t	i;

	i = 0;
	while (arg[i])
	{
		if (!ft_isalnum(arg[i]) && arg[i] != '_')
			return (FALSE);
		i ++;
	}
	return (TRUE);
}

static int	unset_single(char *arg, t_shell *data)
{
	size_t	i;
	char	*temp;

	i = 0;
	while (data->envp[i])
	{
		temp = get_key(data->envp[i]);
		if (ft_strcmp(arg, temp) == 0)
		{
			free(data->envp[i]);
			while (data->envp[i + 1] != NULL)
			{
				data->envp[i] = data->envp[i + 1];
				i ++;
			}
			data->envp[i] = NULL;
			free(temp);
			return (SUCCESS);
		}
		free(temp);
		i ++;
	}
	return (SUCCESS);
}

int	execute_unset_cmd(char **args, t_shell *data)
{
	size_t	i;

	i = 0;
	while (args[i])
	{
		if (!is_valid_var(args[i]))
		{
			print_env_error(args[i], "not a valid identifier");
			return (ERROR);
		}
		if (unset_single(args[i], data) == ERROR)
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}
