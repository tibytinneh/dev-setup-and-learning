/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtanama <rtanama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 05:09:57 by aang-shu          #+#    #+#             */
/*   Updated: 2024/07/14 06:11:43 by rtanama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	verify_quotes(char *input)
{
	int		is_in_quote;
	char	current_quote_type;
	size_t	i;

	is_in_quote = FALSE;
	current_quote_type = '\0';
	i = 0;
	while (i < ft_strlen(input))
	{
		if (input[i] == '\'' || input[i] == '\"')
		{
			if (!is_in_quote)
			{
				is_in_quote = TRUE;
				current_quote_type = input[i];
			}
			else if (current_quote_type == input[i])
				is_in_quote = FALSE;
		}
		i ++;
	}
	if (is_in_quote == TRUE)
		return (ERROR);
	return (SUCCESS);
}

static void	initialize_lexer(t_token **tokens, size_t *i, int *position)
{
	*tokens = NULL;
	*i = 0;
	*position = 0;
}

static t_token	*handle_error(void)
{
	print_error("quote", 0, "invalid quotation syntax");
	return (NULL);
}

t_token	*lexer(const char *input)
{
	t_token	*tokens;
	size_t	i;
	int		position;

	if (verify_quotes((char *)input) == ERROR)
		return (handle_error());
	initialize_lexer(&tokens, &i, &position);
	while (input[i])
	{
		if (ft_isspace(input[i]))
			i++;
		else if (input[i] == '&' || input[i] == '|'
			|| input[i] == '>' || input[i] == '<')
			handle_special_tokens(input, &i, &tokens, &position);
		else if (input[i] == '\'' || input[i] == '\"')
			handle_quotes(input, &i, &tokens, &position);
		else if (input[i] == ')' || input[i] == '(')
			handle_paren_tokens(input, &i, &tokens, &position);
		else
			handle_words(input, &i, &tokens, &position);
	}
	add_token(&tokens, create_token(TOKEN_EOF, NULL, position));
	return (tokens);
}
