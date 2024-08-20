/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input_handler.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtanama <rtanama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:39:16 by rtanama           #+#    #+#             */
/*   Updated: 2024/07/11 00:33:26 by rtanama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	handle_and(t_ast_node *node, t_shell *data)
{
	int	status;

	status = SUCCESS;
	if (!node || !data)
		return (ERROR);
	if (node->left)
		status = execute_cmd(node->left, data);
	if (status == SUCCESS && node->right)
		status = execute_cmd(node->right, data);
	return (status);
}

int	handle_or(t_ast_node *node, t_shell *data)
{
	int	status;

	status = SUCCESS;
	if (!node || !data)
		return (ERROR);
	if (node->left)
		status = execute_cmd(node->left, data);
	if (status != SUCCESS && node->right)
		status = execute_cmd(node->right, data);
	return (status);
}
