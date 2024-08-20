/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtanama <rtanama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 21:03:17 by rtanama           #+#    #+#             */
/*   Updated: 2024/07/13 19:02:13 by rtanama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	count_arguments(t_token *tokens)
{
	size_t	ac;
	t_token	*current;

	ac = 0;
	current = tokens;
	while (current && !is_special_token(current))
	{
		if (is_command_token(current))
			ac++;
		current = current->next;
	}
	return (ac);
}

static int	copy_arguments(t_ast_node *node, t_token *tokens, t_shell *data)
{
	size_t	ac;
	t_token	*current;

	ac = 0;
	current = tokens;
	while (current && !is_special_token(current))
	{
		if (is_command_token(current))
		{
			if (current->type != TOKEN_LITERAL)
				node->args[ac] = expand_env_var(current->content, data);
			else
				node->args[ac] = ft_strdup(current->content);
			if (!node->args[ac])
			{
				free_array_of_strings(node->args);
				return (0);
			}
			ac ++;
		}
		current = current->next;
	}
	node->args[ac] = NULL;
	return (1);
}

t_ast_node	*parse_command(t_token *tokens, t_shell *data)
{
	t_ast_node	*node;
	size_t		ac;

	node = create_ast_node(NODE_COMMAND);
	if (!node)
		return (NULL);
	ac = count_arguments(tokens);
	node->args = (char **)malloc(sizeof(char *) * (ac + 1));
	if (!node->args)
	{
		free_ast_node(node);
		return (NULL);
	}
	if (!copy_arguments(node, tokens, data))
	{
		free_ast_node(node);
		return (NULL);
	}
	return (node);
}

void	free_stack_and_queue(t_queue *output_queue, t_stack *operator_stack)
{
	stack_free(operator_stack);
	queue_free(output_queue);
}
