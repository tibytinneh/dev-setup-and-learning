/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtanama <rtanama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:36:22 by rtanama           #+#    #+#             */
/*   Updated: 2024/07/13 17:40:17 by rtanama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handle_special_tokens_helper(const char *input, size_t *i,
	t_token **tokens, int position)
{
	if (input[*i] == '|' && input[*i + 1] == '|')
	{
		add_token(tokens, create_token(TOKEN_OR, ft_strdup("||"), position));
		*i += 2;
	}
	else if (input[*i] == '|')
	{
		add_token(tokens, create_token(TOKEN_PIPE, ft_strdup("|"), position));
		(*i)++;
	}
	else if (input[*i] == '>' || input[*i] == '<')
	{
		if (input[*i + 1] == input[*i])
		{
			add_token(tokens, create_token(TOKEN_REDIRECTION,
					ft_strndup(input + *i, 2), position));
			*i += 2;
		}
		else
		{
			add_token(tokens, create_token(TOKEN_REDIRECTION,
					ft_strndup(input + *i, 1), position));
			(*i)++;
		}
	}
}

void	handle_special_tokens(const char *input, size_t *i,
	t_token **tokens, int *position)
{
	size_t	start;

	if (input[*i] == '&' && input[*i + 1] == '&')
	{
		add_token(tokens, create_token(TOKEN_AND, ft_strdup("&&"), *position));
		*i += 2;
	}
	else if (input[*i] == '&' && input[*i + 1] != '&')
	{
		start = *i;
		(*i)++;
		while (ft_isalnum(input[*i]))
			(*i)++;
		add_token(tokens, create_token(TOKEN_ARGUMENT,
				ft_strndup(input + start, *i - start), *position));
	}
	handle_special_tokens_helper(input, i, tokens, *position);
	*position += 1;
}

void	handle_quotes(const char *input, size_t *i,
	t_token **tokens, int *position)
{
	char	quote;
	size_t	start;

	quote = input[*i];
	start = ++(*i);
	while (input[*i] && input[*i] != quote)
		(*i)++;
	if (input[*i] == quote)
		(*i)++;
	if (quote == '\'')
	{
		add_token(tokens, create_token(TOKEN_LITERAL,
				ft_strndup(input + start, *i - start - 1), *position));
	}
	else
	{
		add_token(tokens, create_token(TOKEN_ARGUMENT,
				ft_strndup(input + start, *i - start - 1), *position));
	}
	*position += 1;
}

void	handle_words(const char *input, size_t *i, t_token **tokens,
	int *position)
{
	size_t	start;
	char	*word;
	int		is_literal;

	start = *i;
	is_literal = FALSE;
	advance_through_string(input, i, &is_literal);
	word = ft_strndup(input + start, *i - start);
	if (is_literal == TRUE)
		add_token(tokens, create_token(TOKEN_LITERAL, word, *position));
	else
		add_token(tokens, create_token(TOKEN_ARGUMENT, word, *position));
	*position += 1;
}
