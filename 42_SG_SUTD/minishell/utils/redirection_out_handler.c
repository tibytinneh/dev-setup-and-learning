/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_out_handler.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtanama <rtanama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 02:15:34 by rtanama           #+#    #+#             */
/*   Updated: 2024/07/12 17:31:36 by rtanama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	handle_middle(t_ast_node **node)
{
	int		fd;
	char	*filename;

	while ((*node)->left->type == NODE_REDIRECT_OUT
		|| (*node)->left->type == NODE_REDIRECT_APPEND)
	{
		filename = (*node)->left->right->args[0];
		fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd == -1)
		{
			print_error(filename, ENOENT, NULL);
			return (ERROR);
		}
		close(fd);
		*node = (*node)->left;
	}
	return (SUCCESS);
}

static int	setup_redirection_out(char *filename, int *saved_stdout,
	t_ast_node **node)
{
	int	fd;

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (handle_middle(node) == ERROR)
		return (ERROR);
	if (fd == -1)
	{
		print_error(filename, ENOENT, NULL);
		return (ERROR);
	}
	*saved_stdout = dup(STDOUT_FILENO);
	if (*saved_stdout == -1)
	{
		close(fd);
		return (ERROR);
	}
	if (dup2(fd, STDOUT_FILENO) == -1)
	{
		close(fd);
		return (ERROR);
	}
	close(fd);
	return (SUCCESS);
}

static void	restore_stdout(int saved_stdout)
{
	dup2(saved_stdout, STDOUT_FILENO);
	close(saved_stdout);
}

int	handle_redirection_out(t_ast_node *node, t_shell *data)
{
	int		saved_stdout;
	int		status;
	char	*filename;

	filename = node->right->args[0];
	if (setup_redirection_out(filename, &saved_stdout, &node) == ERROR)
		return (ERROR);
	status = execute_cmd(node->left, data);
	restore_stdout(saved_stdout);
	return (status);
}
