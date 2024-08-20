/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtanama <rtanama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:18:02 by rtanama           #+#    #+#             */
/*   Updated: 2024/07/13 17:38:11 by rtanama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_tokenized_input(t_token *tokens)
{
	t_token	*temp;

	while (tokens)
	{
		temp = tokens;
		tokens = tokens->next;
		free(temp->content);
		free(temp);
	}
}

/* lst new node? */
t_token	*create_token(t_token_type type, char *content, int position)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->type = type;
	token->content = content;
	token->next = NULL;
	token->position = position;
	return (token);
}

/*lst add back? */
void	add_token(t_token **tokens, t_token *new_token)
{
	t_token	*temp;

	temp = *tokens;
	if (!temp)
	{
		*tokens = new_token;
		return ;
	}
	while (temp->next)
		temp = temp->next;
	temp->next = new_token;
}

void	skip_quoted_string(const char *input, size_t *i, char quote_char)
{
	(*i)++;
	while (input[*i] && input[*i] != quote_char)
		(*i)++;
	if (input[*i] == quote_char)
		(*i)++;
}

void	advance_through_string(const char *input, size_t *i, int *is_literal)
{
	while (input[*i])
	{
		if (input[*i] == '"' || input[*i] == '\'')
		{
			if (input[*i] == '\'')
				*is_literal = TRUE;
			skip_quoted_string(input, i, input[*i]);
		}
		else if (ft_isspace(input[*i]) || ft_strchr("|&><()", input[*i]))
			break ;
		else
			(*i)++;
	}
}
