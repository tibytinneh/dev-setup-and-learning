/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtanama <rtanama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:37:32 by rtanama           #+#    #+#             */
/*   Updated: 2024/07/13 19:03:30 by rtanama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	push_all_stack_to_queue(t_stack *stack, t_queue *queue)
{
	while (stack_peek(stack))
	{
		if (queue_push(queue, stack_pop(stack)) == ERROR)
			return (ERROR);
	}
	return (SUCCESS);
}

static t_queue	*create_reverse_polish_queue(t_token *tokens, t_shell *data)
{
	t_token		*current;
	t_queue		*output_queue;
	t_stack		*operator_stack;

	current = tokens;
	output_queue = queue_init();
	operator_stack = stack_init();
	while (current && current->type != TOKEN_EOF)
	{
		if (process_token(&current, output_queue,
				operator_stack, data) == ERROR)
		{
			free_stack_and_queue(output_queue, operator_stack);
			return (NULL);
		}
		current = current->next;
	}
	if (push_all_stack_to_queue(operator_stack, output_queue) == ERROR)
	{
		free_stack_and_queue(output_queue, operator_stack);
		return (NULL);
	}
	stack_free(operator_stack);
	return (output_queue);
}

t_ast_node	*parse_tokens(t_token *tokens, t_shell *data)
{
	t_queue		*reverse_polish_queue;
	t_ast_node	*out;

	if (check_parentheses_valid(tokens) == ERROR)
	{
		ft_putstr_fd("Hammu Shell: syntax error near unexpected token\n",
			STDERR_FILENO);
		return (NULL);
	}
	reverse_polish_queue = create_reverse_polish_queue(tokens, data);
	out = create_ast_from_queue(reverse_polish_queue);
	queue_free(reverse_polish_queue);
	return (out);
}
