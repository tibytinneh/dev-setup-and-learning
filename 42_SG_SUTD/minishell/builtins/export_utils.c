/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtanama <rtanama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 01:32:02 by rtanama           #+#    #+#             */
/*   Updated: 2024/07/14 11:14:09 by rtanama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_env_error(char *arg, char *message)
{
	char	*out;

	out = ft_strjoin(arg, message);
	print_error("export", 0, out);
	free(out);
}

char	*get_key(char *arg)
{
	int		i;
	char	*key;

	i = 0;
	if (ft_isdigit(arg[i]))
		return (NULL);
	while (arg[i] && arg[i] != '=')
	{
		if (!ft_isalnum(arg[i]) && arg[i] != '_')
			return (NULL);
		i++;
	}
	key = ft_strndup(arg, i);
	return (key);
}

char	*remove_quotes(const char *arg)
{
	char		*result;
	char		*ptr;
	const char	*temp;
	size_t		len;

	temp = arg;
	len = 0;
	while (*temp)
	{
		if (*temp != '\'' && *temp != '"')
			len++;
		temp++;
	}
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	ptr = result;
	while (*arg)
	{
		if (*arg != '\'' && *arg != '"')
			*ptr++ = *arg;
		arg++;
	}
	*ptr = '\0';
	return (result);
}

static int	end_export_without_argument(char **sorted_env, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		ft_putstr_fd("declare -x ", STDOUT_FILENO);
		ft_putendl_fd(sorted_env[i], STDOUT_FILENO);
		i++;
	}
	free_array_of_strings(sorted_env);
	return (SUCCESS);
}

int	export_without_argument(char ***envp)
{
	int		i;
	int		count;
	char	**sorted_env;

	count = 0;
	while ((*envp)[count])
		count++;
	sorted_env = malloc(sizeof(char *) * (count + 1));
	i = 0;
	while (i < count)
	{
		sorted_env[i] = ft_strdup((*envp)[i]);
		if (!sorted_env[i])
		{
			print_error("export", 0, "failed to allocate memory");
			free_array_of_strings(sorted_env);
			return (ERROR);
		}
		i++;
	}
	sorted_env[i] = NULL;
	ft_bubble_sort(sorted_env, count);
	return (end_export_without_argument(sorted_env, count));
}
