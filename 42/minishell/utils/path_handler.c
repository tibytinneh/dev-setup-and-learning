/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtanama <rtanama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 21:15:27 by rtanama           #+#    #+#             */
/*   Updated: 2024/07/18 03:01:30 by rtanama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*resolve_relative_path(char *cmd)
{
	char	resolved_path[PATH_MAX];

	if (getcwd(resolved_path, PATH_MAX) != NULL)
	{
		ft_strlcat(resolved_path, "/", PATH_MAX);
		ft_strlcat(resolved_path, cmd, PATH_MAX);
		return (ft_strdup(resolved_path));
	}
	return (NULL);
}

static char	*find_executable_path(char **split_paths, char *cmd)
{
	char	*abs_path;
	size_t	i;

	i = 0;
	while (split_paths[i] != NULL)
	{
		abs_path = append_path(split_paths[i], cmd);
		if (access(abs_path, X_OK) == 0)
			return (abs_path);
		free(abs_path);
		i ++;
	}
	return (NULL);
}

int	get_path_validity(char *path)
{
	char	*relative;

	if (path[0] == '/')
	{
		if (access(path, F_OK) != 0)
			return (NOT_FOUND);
		if (access(path, X_OK) != 0)
			return (NO_PERMISSION);
	}
	else if (ft_strchr(path, '/') != NULL)
	{
		relative = resolve_relative_path(path);
		if (access(relative, F_OK) != 0)
			return (NOT_FOUND);
		if (access(relative, X_OK) != 0)
		{
			free(relative);
			return (NO_PERMISSION);
		}
		free(relative);
	}
	return (SUCCESS);
}

char	*extract_abs_path(char *cmd, char **envp)
{
	char		*path;
	char		*abs_path;
	char		**split_paths;

	if (cmd[0] == '/' && access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	if (ft_strchr(cmd, '/') != NULL)
	{
		abs_path = resolve_relative_path(cmd);
		if (abs_path)
			return (abs_path);
	}
	path = extract_pathvar(envp);
	split_paths = ft_split(path, ':');
	if (split_paths == NULL)
		return (NULL);
	free(path);
	abs_path = find_executable_path(split_paths, cmd);
	if (abs_path != NULL)
	{
		free_array_of_strings(split_paths);
		return (abs_path);
	}
	free_array_of_strings(split_paths);
	return (NULL);
}
