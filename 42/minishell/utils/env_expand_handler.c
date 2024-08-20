/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_expand_handler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtanama <rtanama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:54:17 by rtanama           #+#    #+#             */
/*   Updated: 2024/07/14 06:15:41 by rtanama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*expand_single(char *arg, t_shell *data)
{
	char	*out;
	int		envp_index;

	arg = arg + 1;
	if (*arg == '?')
	{
		out = ft_itoa(g_exit_code);
		return (out);
	}
	envp_index = find_env_var(data->envp, arg);
	if (envp_index != -1)
		out = ft_strdup(ft_strchr(data->envp[envp_index], '=') + 1);
	else
		out = ft_strdup("");
	return (out);
}

static char	*expand_variable(char **out, char *start, char *arg, t_shell *data)
{
	char	*end;
	char	*tmp;
	char	*expanded;
	char	*new_out;

	end = start + 1;
	while (ft_isalnum(*end) || *end == '_' || *end == '?')
		end++;
	tmp = ft_substr(arg, start - arg, end - start);
	expanded = expand_single(tmp, data);
	new_out = ft_strjoin(*out, expanded);
	free(expanded);
	free(tmp);
	free(*out);
	*out = new_out;
	return (end);
}

static char	*expand(char *arg, t_shell *data)
{
	char	*out;
	char	*tmp;
	char	*start;
	char	*new_out;

	out = ft_strdup("");
	start = arg;
	while (*start)
	{
		if (*start == '$')
			start = expand_variable(&out, start, arg, data);
		else
		{
			tmp = ft_substr(arg, start - arg, 1);
			new_out = ft_strjoin(out, tmp);
			free(tmp);
			free(out);
			out = new_out;
			start++;
		}
	}
	return (out);
}

char	*expand_env_var(char *arg, t_shell *data)
{
	char	*out;

	out = expand(arg, data);
	return (out);
}
