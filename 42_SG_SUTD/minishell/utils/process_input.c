/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtanama <rtanama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 01:40:13 by aang-shu          #+#    #+#             */
/*   Updated: 2024/07/14 06:57:58 by rtanama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	handle_non_command(t_ast_node *node, t_shell *data)
{
	int	status;

	status = SUCCESS;
	if (node->type == NODE_AND)
		status = handle_and(node, data);
	else if (node->type == NODE_OR)
		status = handle_or(node, data);
	else if (node->type == NODE_PIPE)
		status = handle_pipe(node, data);
	else if (node->type == NODE_REDIRECT_OUT)
		status = handle_redirection_out(node, data);
	else if (node->type == NODE_REDIRECT_IN)
		status = handle_redirection_in(node, data);
	else if (node->type == NODE_REDIRECT_HEREDOC)
		status = handle_heredoc(node, data);
	else if (node->type == NODE_REDIRECT_APPEND)
		status = handle_append(node, data);
	return (status);
}

int	execute_cmd(t_ast_node *node, t_shell *data)
{
	int		status;

	status = SUCCESS;
	if (!node)
		return (status);
	if (node->type == NODE_COMMAND)
	{
		status = execute_builtin_cmd(node->args[0], node->args, data);
		if (status == NOT_FOUND)
			status = execute_external_cmd(node->args[0], node->args, data);
	}
	else
		status = handle_non_command(node, data);
	if (status != EXIT)
		g_exit_code = status;
	return (status);
}

static	int	check_syntax_error(t_token *tokens)
{
	t_token	*current;

	if (!tokens)
		return (ERROR);
	current = tokens;
	while (current->next)
	{
		if (current->next->type == TOKEN_EOF)
		{
			if (is_operator_token(current))
				return (ERROR);
		}
		current = current->next;
	}
	return (SUCCESS);
}

int	process_input(t_shell *data)
{
	t_token		*tokens;
	t_ast_node	*ast;
	int			status;

	tokens = lexer(data->input_str);
	if (!tokens || tokens->type == TOKEN_EOF)
	{
		free_tokenized_input(tokens);
		return (ERROR);
	}
	if (check_syntax_error(tokens) == ERROR)
	{
		print_error("syntax error", 0, "unexpected token");
		free_tokenized_input(tokens);
		return (ERROR);
	}
	ast = parse_tokens(tokens, data);
	free_tokenized_input(tokens);
	if (!ast)
		return (ERROR);
	status = execute_cmd(ast, data);
	free_ast(ast);
	return (status);
}
