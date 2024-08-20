/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_processor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtanama <rtanama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 01:10:12 by rtanama           #+#    #+#             */
/*   Updated: 2024/07/14 03:17:40 by rtanama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	process_command_token(t_token **c, t_queue *q, t_shell *data)
{
	if (queue_push(q, create_node_based_on_token(*c, data)) == ERROR)
		return (ERROR);
	while ((*c)->next && is_command_token((*c)->next))
		*c = (*c)->next;
	return (SUCCESS);
}

static int	process_operator_token(t_token **c, t_queue *q, t_stack *s,
	t_shell *data)
{
	t_ast_node	*temp;

	temp = create_node_based_on_token(*c, data);
	if (!temp)
		return (ERROR);
	while (stack_peek(s) && get_operator_precedence(temp)
		<= get_operator_precedence(stack_peek(s)))
	{
		if (queue_push(q, stack_pop(s)) == ERROR)
		{
			free_ast_node(temp);
			return (ERROR);
		}
	}
	if (stack_push(s, temp) == ERROR)
	{
		free_ast_node(temp);
		return (ERROR);
	}
	return (SUCCESS);
}

static int	process_command_and_operator_tokens(t_token **c, t_queue *q,
	t_stack *s, t_shell *data)
{
	if (is_command_token(*c))
	{
		if (process_command_token(c, q, data) == ERROR)
			return (ERROR);
	}
	else if (is_operator_token(*c))
	{
		if (process_operator_token(c, q, s, data) == ERROR)
			return (ERROR);
	}
	return (SUCCESS);
}

static int	process_parentheses_tokens(t_token **c, t_queue *q, t_stack *s,
	t_shell *data)
{
	if ((*c)->type == TOKEN_OPEN_PAREN)
	{
		if (stack_push(s, create_node_based_on_token(*c, data)) == ERROR)
			return (ERROR);
	}
	else if ((*c)->type == TOKEN_CLOSE_PAREN)
	{
		while (stack_peek(s) && stack_peek(s)->type != NODE_OPEN_PAREN)
		{
			if (queue_push(q, stack_pop(s)) == ERROR)
				return (ERROR);
		}
		stack_pop(s);
	}
	return (SUCCESS);
}

int	process_token(t_token **c, t_queue *q, t_stack *s, t_shell *data)
{
	if (is_command_token(*c) || is_operator_token(*c))
	{
		if (process_command_and_operator_tokens(c, q, s, data) == ERROR)
			return (ERROR);
	}
	else if ((*c)->type == TOKEN_OPEN_PAREN || (*c)->type == TOKEN_CLOSE_PAREN)
	{
		if (process_parentheses_tokens(c, q, s, data) == ERROR)
			return (ERROR);
	}
	return (SUCCESS);
}
