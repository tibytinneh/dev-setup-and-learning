/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtanama <rtanama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 02:12:25 by rtanama           #+#    #+#             */
/*   Updated: 2024/07/11 01:42:38 by rtanama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Checks the balance of parentheses in a list of tokens.
 *
 * @param tokens The list of tokens to check.
 * @return Returns SUCCESS if the parentheses are balanced,
 * otherwise returns ERROR.
 */
static int	check_parentheses_balance(t_token *tokens)
{
	t_token	*current;
	int		open_parentheses_count;

	current = tokens;
	open_parentheses_count = 0;
	while (current)
	{
		if (current->type == TOKEN_OPEN_PAREN)
			open_parentheses_count++;
		else if (current->type == TOKEN_CLOSE_PAREN)
		{
			open_parentheses_count--;
			if (open_parentheses_count < 0)
				return (ERROR);
		}
		current = current->next;
	}
	if (open_parentheses_count != 0)
		return (ERROR);
	return (SUCCESS);
}

/**
 * Validates the positions of parentheses in a token list.
 *
 * @param tokens The token list to validate.
 * @return Returns SUCCESS if the parentheses positions are valid,
 * otherwise returns ERROR.
 */
static int	validate_parentheses_positions(t_token *tokens)
{
	t_token	*prev;
	t_token	*current;

	prev = NULL;
	current = tokens;
	while (current)
	{
		if (current->type == TOKEN_OPEN_PAREN && prev
			&& prev->type != TOKEN_OPEN_PAREN && prev->type != TOKEN_AND
			&& prev->type != TOKEN_OR)
			return (ERROR);
		if (current->type == TOKEN_OPEN_PAREN && (!current->next
				|| current->next->type == TOKEN_CLOSE_PAREN))
			return (ERROR);
		if (current->type == TOKEN_CLOSE_PAREN
			&& current->next && current->next->type != TOKEN_EOF
			&& current->next->type != TOKEN_AND
			&& current->next->type != TOKEN_OR
			&& current->next->type != TOKEN_CLOSE_PAREN)
			return (ERROR);
		prev = current;
		current = current->next;
	}
	return (SUCCESS);
}

/**
 * Checks if the parentheses in the given tokens are valid.
 *
 * This function first checks if the parentheses are balanced, meaning that
 * each opening parenthesis has a corresponding closing parenthesis. If the
 * parentheses are not balanced, it returns an error.
 *
 * If the parentheses are balanced, this function then validates the positions
 * of the parentheses. It checks if the parentheses are in the correct order
 * and returns an error if they are not.
 *
 * @param tokens The tokens containing the parentheses to be checked.
 * @return Returns ERROR if the parentheses are not valid, otherwise returns
 *         success.
 */
int	check_parentheses_valid(t_token *tokens)
{
	if (check_parentheses_balance(tokens) == ERROR)
		return (ERROR);
	return (validate_parentheses_positions(tokens));
}
