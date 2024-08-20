/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtanama <rtanama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 23:24:15 by rtanama           #+#    #+#             */
/*   Updated: 2024/07/14 10:19:54 by rtanama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handle_child(t_ast_node *node, int fd[2], t_shell *data,
	int *stdin_copy)
{
	char	*delimiter;

	delimiter = node->right->args[0];
	close(fd[0]);
	signal(SIGINT, child_sigint_handler);
	handle_child_loop_heredoc(fd, delimiter, data);
	close(fd[1]);
	handle_cleanup_heredoc(*stdin_copy);
	if (g_exit_code == SIGINT_EXIT_CODE)
		exit(SIGINT_EXIT_CODE);
	exit(EXIT_SUCCESS);
}

static int	end(int *stdin_copy, t_ast_node *node, t_shell *data, int status)
{
	signal(SIGINT, sigint_handler);
	execute_cmd(node->left, data);
	handle_cleanup_heredoc(*stdin_copy);
	return (status);
}

int	handle_heredoc(t_ast_node *node, t_shell *data)
{
	int		fd[2];
	int		status;
	int		stdin_copy;
	pid_t	pid;

	signal(SIGINT, child_sigint_handler);
	stdin_copy = dup(STDIN_FILENO);
	if (pipe(fd) == -1)
		return (ERROR);
	g_exit_code = EXIT_SUCCESS;
	pid = fork();
	if (pid == 0)
		handle_child(node, fd, data, &stdin_copy);
	else if (pid < 0)
		return (handle_error_heredoc(fd));
	close(fd[1]);
	if (dup2(fd[0], STDIN_FILENO) == -1)
		return (handle_dup_error_heredoc(fd));
	close(fd[0]);
	waitpid(pid, &status, 0);
	return (end(&stdin_copy, node, data, WEXITSTATUS(status)));
}
