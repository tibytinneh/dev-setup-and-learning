/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_token_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtanama <rtanama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 23:55:35 by rtanama           #+#    #+#             */
/*   Updated: 2024/07/13 17:43:29 by rtanama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_special_token(t_token *token)
{
	return (token->type == TOKEN_PIPE
		|| token->type == TOKEN_AND
		|| token->type == TOKEN_OR
		|| token->type == TOKEN_REDIRECTION);
}

int	is_and_or_token(t_token *token)
{
	return (token->type == TOKEN_AND || token->type == TOKEN_OR);
}

int	is_operator_token(t_token *token)
{
	return (is_special_token(token) || is_and_or_token(token));
}

int	is_command_token(t_token *token)
{
	return (token->type == TOKEN_ARGUMENT || token->type == TOKEN_LITERAL);
}

int	get_operator_precedence(t_ast_node *operator_node)
{
	if (operator_node->type == NODE_OPEN_PAREN
		|| operator_node->type == NODE_CLOSE_PAREN)
		return (0);
	else if (operator_node->type == NODE_AND || operator_node->type == NODE_OR)
		return (1);
	else
		return (2);
}
