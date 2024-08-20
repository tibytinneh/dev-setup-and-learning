/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtanama <rtanama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:33:14 by rtanama           #+#    #+#             */
/*   Updated: 2024/07/13 17:52:26 by rtanama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_ast_node	*create_ast_node(t_node_type type)
{
	t_ast_node	*new_node;

	new_node = (t_ast_node *)malloc(sizeof(t_ast_node));
	if (!new_node)
		return (NULL);
	new_node->type = type;
	new_node->args = NULL;
	new_node->filename = NULL;
	new_node->left = NULL;
	new_node->right = NULL;
	return (new_node);
}

void	free_ast_node(t_ast_node *node)
{
	size_t	i;

	if (!node)
		return ;
	if (node->args)
	{
		i = 0;
		while (node->args[i])
		{
			free(node->args[i]);
			i ++;
		}
		free(node->args);
	}
	if (node->filename)
		free(node->filename);
	free(node);
}

void	free_ast(t_ast_node *root)
{
	if (!root)
		return ;
	free_ast(root->left);
	free_ast(root->right);
	free_ast_node(root);
}

t_ast_node	*create_node_based_on_token(t_token *current, t_shell *data)
{
	if (current->type == TOKEN_PIPE)
		return (create_ast_node(NODE_PIPE));
	else if (current->type == TOKEN_OR)
		return (create_ast_node(NODE_OR));
	else if (current->type == TOKEN_AND)
		return (create_ast_node(NODE_AND));
	else if (current->type == TOKEN_REDIRECTION)
	{
		if (ft_strcmp(current->content, ">") == 0)
			return (create_ast_node(NODE_REDIRECT_OUT));
		else if (ft_strcmp(current->content, "<") == 0)
			return (create_ast_node(NODE_REDIRECT_IN));
		else if (ft_strcmp(current->content, ">>") == 0)
			return (create_ast_node(NODE_REDIRECT_APPEND));
		else if (ft_strcmp(current->content, "<<") == 0)
			return (create_ast_node(NODE_REDIRECT_HEREDOC));
	}
	else if (current->type == TOKEN_OPEN_PAREN)
		return (create_ast_node(NODE_OPEN_PAREN));
	else if (current->type == TOKEN_CLOSE_PAREN)
		return (create_ast_node(NODE_CLOSE_PAREN));
	else
		return (parse_command(current, data));
	return (NULL);
}

t_ast_node	*create_ast_from_queue(t_queue *queue)
{
	t_ast_node	*current_node;
	t_stack		*operand_stack;

	operand_stack = stack_init();
	while (queue_peek(queue))
	{
		current_node = queue_pop(queue);
		if (current_node->type == NODE_COMMAND)
		{
			if (stack_push(operand_stack, current_node) == ERROR)
				break ;
		}
		else
		{
			current_node->right = stack_pop(operand_stack);
			current_node->left = stack_pop(operand_stack);
			if (stack_push(operand_stack, current_node) == ERROR)
				break ;
		}
	}
	current_node = stack_pop(operand_stack);
	stack_free(operand_stack);
	return (current_node);
}
