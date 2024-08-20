/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_queue.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtanama <rtanama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 22:16:48 by rtanama           #+#    #+#             */
/*   Updated: 2024/07/11 00:59:05 by rtanama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_queue	*queue_init(void)
{
	t_queue	*queue;

	queue = (t_queue *)malloc(sizeof(t_queue));
	if (!queue)
		return (NULL);
	queue->front = NULL;
	queue->rear = NULL;
	queue->size = 0;
	return (queue);
}

int	queue_push(t_queue *queue, t_ast_node *value)
{
	t_queue_node	*new_node;

	if (value == NULL)
		return (SUCCESS);
	new_node = (t_queue_node *)malloc(sizeof(t_queue_node));
	if (!new_node)
		return (ERROR);
	new_node->value = value;
	new_node->next = NULL;
	if (queue->rear)
		queue->rear->next = new_node;
	queue->rear = new_node;
	if (!queue->front)
		queue->front = new_node;
	queue->size++;
	return (SUCCESS);
}

t_ast_node	*queue_pop(t_queue *queue)
{
	t_queue_node	*temp;
	t_ast_node		*front;

	if (!queue->front)
		return (NULL);
	temp = queue->front;
	front = temp->value;
	queue->front = queue->front->next;
	if (!queue->front)
		queue->rear = NULL;
	queue->size--;
	free(temp);
	return (front);
}

t_ast_node	*queue_peek(t_queue *queue)
{
	if (!queue->front)
		return (NULL);
	return (queue->front->value);
}

void	queue_free(t_queue *queue)
{
	t_queue_node	*current;
	t_queue_node	*next;

	if (queue == NULL)
		return ;
	current = queue->front;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(queue);
}
