/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_external_cmd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtanama <rtanama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 21:14:38 by rtanama           #+#    #+#             */
/*   Updated: 2024/07/11 19:26: by rtanama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handle_child_pid(char *abs_path, char **args, t_shell *data)
{
	if (isatty(STDIN_FILENO))
		enable_ctrl_backslash_echo();
	execve(abs_path, args, data->envp);
	exit(errno);
}

static void	cleanup_signals(void)
{
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, sigquit_handler);
	if (isatty(STDIN_FILENO))
		disable_ctrl_backslash_echo();
}

static int	abs_path_not_found(char *command)
{
	cleanup_signals();
	print_error(command, 0, "command not found");
	return (COMMAND_NOT_FOUND_EXIT_CODE);
}

static int	handle_invalid_path(char *command, int status)
{
	cleanup_signals();
	if (status == NOT_FOUND)
	{
		print_error(command, 0, "command not found");
		return (COMMAND_NOT_FOUND_EXIT_CODE);
	}
	else if (status == NO_PERMISSION)
	{
		print_error(command, 0, "Permission denied");
		return (PERMISSION_DENIED_EXIT_CODE);
	}
	else
	{
		print_error(command, 0, "Unable to execute command");
		return (ERROR);
	}
}

int	execute_external_cmd(char *command, char **args, t_shell *data)
{
	pid_t	pid;
	char	*abs_path;
	int		status;

	signal(SIGINT, child_sigint_handler_external);
	signal(SIGQUIT, handle_child_sigquit);
	if (get_path_validity(command) != SUCCESS)
		return (handle_invalid_path(command, get_path_validity(command)));
	abs_path = extract_abs_path(command, data->envp);
	if (!abs_path)
		return (abs_path_not_found(command));
	pid = fork();
	if (pid == 0)
		handle_child_pid(abs_path, args, data);
	else if (pid < 0)
		return (ERROR);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		status = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		status = WTERMSIG(status) + 128;
	free(abs_path);
	cleanup_signals();
	return (status);
}
