/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aang-shu <aang-shu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 10:12:45 by aang-shu          #+#    #+#             */
/*   Updated: 2024/06/16 19:53:18 by aang-shu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_argument_count(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i] != NULL)
		i ++;
	return (i - 1);
}

static size_t	count_arguments(t_token *tokens)
{
	size_t	count;
	t_token	*temp;

	count = 0;
	temp = tokens;
	while (temp)
	{
		if (temp->type == TOKEN_ARGUMENT)
			count++;
		temp = temp->next;
	}
	return (count);
}

static void	*free_args(char **args)
{
	size_t	i;

	i = 0;
	while (args[i] != NULL)
	{
		free(args[i]);
		i++;
	}
	free(args);
	return (NULL);
}

static char	**allocate_and_populate_args(t_token *tokens,
	size_t count)
{
	char	**args;
	size_t	i;
	t_token	*temp;

	args = malloc(sizeof(char *) * (count + 1));
	if (!args)
		return (NULL);
	i = 0;
	temp = tokens;
	while (temp)
	{
		if (temp->type == TOKEN_ARGUMENT)
		{
			args[i] = ft_strdup(temp->content);
			if (!args[i])
				return (free_args(args));
			i++;
		}
		temp = temp->next;
	}
	args[i] = NULL;
	return (args);
}

char	**get_cmd_args(t_token *tokens)
{
	size_t	count;

	count = count_arguments(tokens);
	return (allocate_and_populate_args(tokens, count));
}
