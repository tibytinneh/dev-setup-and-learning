/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_paren.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtanama <rtanama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 23:13:13 by rtanama           #+#    #+#             */
/*   Updated: 2024/07/10 17:28:06 by rtanama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_paren_tokens(const char *input, size_t *i,
	t_token **tokens, int *position)
{
	if (input[*i] == '(')
	{
		add_token(tokens, create_token(TOKEN_OPEN_PAREN,
				ft_strdup("("), *position));
		(*i)++;
	}
	else if (input[*i] == ')')
	{
		add_token(tokens, create_token(TOKEN_CLOSE_PAREN,
				ft_strdup(")"), *position));
		(*i)++;
	}
	(*position)++;
}
