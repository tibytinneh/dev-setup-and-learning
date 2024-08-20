/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtanama <rtanama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 23:49:45 by rtanama           #+#    #+#             */
/*   Updated: 2024/07/14 07:09:54 by rtanama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	init_pipe(t_pipe *pipe_obj)
{
	if (pipe(pipe_obj->pipe_fd) == -1)
		return (ERROR);
	return (SUCCESS);
}

static void	handle_child_process(t_pipe *pipe_obj, t_ast_node *node,
	t_shell *data, int write)
{
	int	status;
	int	fileno;

	if (write)
		fileno = STDOUT_FILENO;
	else
		fileno = STDIN_FILENO;
	close(pipe_obj->pipe_fd[1 - write]);
	if (dup2(pipe_obj->pipe_fd[write], fileno) == -1)
	{
		close(pipe_obj->pipe_fd[write]);
		exit(ERROR);
	}
	close(pipe_obj->pipe_fd[write]);
	status = execute_cmd(node, data);
	exit(status);
}

static int	fork_and_execute_child(t_pipe *pipe_obj, t_ast_node *node,
	t_shell *data, int is_left)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		handle_child_process(pipe_obj, node, data, is_left);
		exit(EXIT_SUCCESS);
	}
	else if (pid < 0)
	{
		close(pipe_obj->pipe_fd[0]);
		close(pipe_obj->pipe_fd[1]);
		return (ERROR);
	}
	return (pid);
}

int	handle_pipe(t_ast_node *node, t_shell *data)
{
	int		status;
	t_pipe	pipe_obj;
	pid_t	pid1;
	pid_t	pid2;

	status = init_pipe(&pipe_obj);
	if (status == -1)
		return (ERROR);
	pid1 = fork_and_execute_child(&pipe_obj, node->left, data, 1);
	if (pid1 == ERROR)
		return (ERROR);
	pid2 = fork_and_execute_child(&pipe_obj, node->right, data, 0);
	if (pid2 == ERROR)
		return (ERROR);
	close(pipe_obj.pipe_fd[0]);
	close(pipe_obj.pipe_fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, &status, 0);
	return (WEXITSTATUS(status));
}
