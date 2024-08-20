/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_in_handler.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtanama <rtanama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 03:30:06 by rtanama           #+#    #+#             */
/*   Updated: 2024/07/18 03:24:34 by rtanama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	handle_middle(t_ast_node **node)
{
	int		fd;
	char	*filename;

	while ((*node)->left->type == NODE_REDIRECT_IN)
	{
		filename = (*node)->left->right->args[0];
		fd = open(filename, O_RDONLY, 0644);
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

static int	setup_redirection_in(char *filename, int *saved_stdin,
	t_ast_node **node, int is_reversed)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (!is_reversed)
		if (handle_middle(node) == ERROR)
			return (ERROR);
	if (fd == -1)
	{
		print_error(filename, ENOENT, NULL);
		return (ERROR);
	}
	*saved_stdin = dup(STDIN_FILENO);
	if (*saved_stdin == -1)
	{
		close(fd);
		return (ERROR);
	}
	if (dup2(fd, STDIN_FILENO) == -1)
	{
		close(fd);
		return (ERROR);
	}
	close(fd);
	return (SUCCESS);
}

static void	restore_stdin(int saved_stdin)
{
	dup2(saved_stdin, STDIN_FILENO);
	close(saved_stdin);
}

static void	reverse_args(char **args)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (args[i])
		i ++;
	j = 0;
	i = i - 1;
	while (j < i)
	{
		temp = args[i];
		args[i] = args[j];
		args[j] = temp;
		i--;
		j++;
	}
}

int	handle_redirection_in(t_ast_node *node, t_shell *data)
{
	int		saved_stdin;
	char	*filename;
	int		status;

	filename = node->right->args[0];
	if (node->left == NULL)
	{
		if (setup_redirection_in(filename, &saved_stdin, &node, TRUE) == ERROR)
			return (ERROR);
		reverse_args(node->right->args);
		status = execute_cmd(node->right, data);
		restore_stdin(saved_stdin);
		return (status);
	}
	else
	{
		if (setup_redirection_in(filename, &saved_stdin, &node, FALSE) == ERROR)
			return (ERROR);
		status = execute_cmd(node->left, data);
		restore_stdin(saved_stdin);
		return (status);
	}
}
