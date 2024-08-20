/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtanama <rtanama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 16:35:57 by aang-shu          #+#    #+#             */
/*   Updated: 2024/07/14 02:59:41 by rtanama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	find_env_var(char **envp, const char *var)
{
	int	len;
	int	i;

	len = ft_strlen(var);
	i = 0;
	if (envp == NULL)
		return (-1);
	while (envp[i] != NULL)
	{
		if ((ft_strncmp(envp[i], var, len) == 0 && envp[i][len] == '='))
			return (i);
		i++;
	}
	return (-1);
}

char	*envp_shlvl(char **envp)
{
	int		shlvl_nbr;
	int		shlvl_index;
	char	*shlvl_str;
	char	*new_shlvl;

	shlvl_nbr = 1;
	shlvl_index = find_env_var(envp, "SHLVL");
	if (envp != NULL && shlvl_index != -1
		&& ft_strncmp(envp[shlvl_index], "SHLVL=", 6) == 0)
		shlvl_nbr = ft_atoi(envp[shlvl_index] + 6) + 1;
	shlvl_str = ft_itoa(shlvl_nbr);
	if (!shlvl_str)
		return (NULL);
	new_shlvl = (char *)malloc(7 + ft_strlen(shlvl_str) + 1);
	if (!new_shlvl)
	{
		free(shlvl_str);
		return (NULL);
	}
	ft_strcpy(new_shlvl, "SHLVL=");
	ft_strcat(new_shlvl, shlvl_str);
	free(shlvl_str);
	return (new_shlvl);
}

int	update_shlvl(char ***envp)
{
	char	*shlvl_str;
	int		index;

	shlvl_str = envp_shlvl(*envp);
	if (!shlvl_str)
	{
		free_array_of_strings(*envp);
		return (ERROR);
	}
	index = find_env_var(*envp, "SHLVL");
	if (index >= 0)
	{
		free((*envp)[index]);
		(*envp)[index] = shlvl_str;
	}
	else
		return (append_env_var(envp, shlvl_str));
	return (SUCCESS);
}

int	append_env_var(char ***envp, char *new_var)
{
	int		i;
	char	**new_envp;

	i = 0;
	while ((*envp)[i] != NULL)
		i++;
	new_envp = ft_realloc(*envp, sizeof(char *) * (i + 2));
	if (!new_envp)
	{
		free(new_var);
		return (ERROR);
	}
	new_envp[i] = new_var;
	new_envp[i + 1] = NULL;
	*envp = new_envp;
	return (SUCCESS);
}

char	**envp_copy(char **envp)
{
	int		i;
	int		len;
	char	**copy;

	len = 0;
	while (envp[len])
		len++;
	copy = malloc((len + 1) * sizeof(char *));
	if (!copy)
		return (NULL);
	i = 0;
	while (envp[i])
	{
		copy[i] = ft_strdup(envp[i]);
		if (!copy[i])
		{
			while (i > 0)
				free(copy[--i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}
