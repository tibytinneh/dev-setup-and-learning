/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtanama <rtanama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:05:26 by rtanama           #+#    #+#             */
/*   Updated: 2024/07/11 00:58:59 by rtanama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_stack	*stack_init(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

int	stack_push(t_stack *stack, t_ast_node *value)
{
	t_stack_node	*new_node;

	if (value == NULL)
		return (SUCCESS);
	new_node = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!new_node)
		return (ERROR);
	new_node->value = value;
	new_node->next = stack->top;
	stack->top = new_node;
	stack->size++;
	return (SUCCESS);
}

t_ast_node	*stack_pop(t_stack *stack)
{
	t_stack_node	*temp;
	t_ast_node		*top;

	if (!stack->top)
		return (NULL);
	temp = stack->top;
	top = temp->value;
	stack->top = stack->top->next;
	stack->size--;
	free(temp);
	return (top);
}

t_ast_node	*stack_peek(t_stack *stack)
{
	if (!stack->top)
		return (NULL);
	return (stack->top->value);
}

void	stack_free(t_stack *stack)
{
	t_stack_node	*current;
	t_stack_node	*next;

	if (stack == NULL)
		return ;
	current = stack->top;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(stack);
}
