/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtanama <rtanama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 03:55:18 by aang-shu          #+#    #+#             */
/*   Updated: 2024/07/14 18:25:44 by rtanama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*make_envp(char *arg)
{
	char	*no_quotes;

	no_quotes = remove_quotes(arg);
	if (!no_quotes)
		return (NULL);
	return (no_quotes);
}

static int	update_existing_env_var(char *arg, char ***envp, char *key)
{
	char	*temp;
	int		i;

	i = 0;
	while ((*envp)[i])
	{
		temp = get_key((*envp)[i]);
		if (ft_strcmp(temp, key) == 0)
		{
			free((*envp)[i]);
			(*envp)[i] = make_envp(arg);
			free(temp);
			return (SUCCESS);
		}
		free(temp);
		i ++;
	}
	return (ERROR);
}

static int	add_new_env_var(char *arg, char ***envp, int i)
{
	char	**temp_envp;
	int		j;

	temp_envp = malloc(sizeof(char *) * (i + 2));
	if (!temp_envp)
		return (ERROR);
	j = 0;
	while (j < i)
	{
		temp_envp[j] = (*envp)[j];
		j ++;
	}
	temp_envp[i] = make_envp(arg);
	if (!temp_envp[i])
		return (ERROR);
	temp_envp[i + 1] = NULL;
	if (*envp != NULL)
		free(*envp);
	*envp = temp_envp;
	return (SUCCESS);
}

static int	handle_individual_export(char *arg, char ***envp)
{
	char	*key;
	int		found;
	int		i;

	key = get_key(arg);
	if (!key)
	{
		print_env_error(arg, ": not a valid identifier");
		return (ERROR);
	}
	found = update_existing_env_var(arg, envp, key);
	if (found == ERROR)
	{
		i = 0;
		while ((*envp)[i])
			i++;
		if (add_new_env_var(arg, envp, i) == ERROR)
		{
			free(key);
			return (ERROR);
		}
	}
	free(key);
	return (SUCCESS);
}

int	execute_export_cmd(char **args, t_shell *data)
{
	size_t	i;

	if (ft_array_len(args) == 1)
		return (export_without_argument(&(data->envp)));
	i = 1;
	while (args[i])
	{
		if (handle_individual_export(args[i], &(data->envp)) == ERROR)
			return (ERROR);
		i ++;
	}
	return (SUCCESS);
}
