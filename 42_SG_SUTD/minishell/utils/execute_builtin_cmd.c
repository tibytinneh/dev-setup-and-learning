/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin_cmd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtanama <rtanama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 10:31:28 by aang-shu          #+#    #+#             */
/*   Updated: 2024/07/14 04:53:58 by rtanama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Returns error by default if command isn't found.
 *
 * @param command The name of the command.
 * @param args The list of arguments.
 * @return int The status of execution.
 */

int	execute_builtin_cmd(char *command, char **args, t_shell *data)
{
	if (ft_strcmp(command, ECHO_CMD) == 0)
		return (execute_echo_cmd(args));
	else if (ft_strcmp(command, ENV_CMD) == 0)
		return (execute_env_cmd(data->envp));
	else if (ft_strcmp(command, CD_CMD) == 0)
		return (execute_cd_cmd(args));
	else if (ft_strcmp(command, EXPORT_CMD) == 0)
		return (execute_export_cmd(args, data));
	else if (ft_strcmp(command, UNSET_CMD) == 0)
		return (execute_unset_cmd(args, data));
	else if (ft_strcmp(command, PWD_CMD) == 0)
		return (execute_pwd_cmd());
	else if (ft_strcmp(command, EXIT_CMD) == 0)
		return (execute_exit_cmd(args));
	else if (ft_strcmp(command, CLEAR_CMD) == 0)
		return (execute_clear_cmd());
	return (NOT_FOUND);
}
