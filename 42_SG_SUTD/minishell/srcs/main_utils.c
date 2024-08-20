/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtanama <rtanama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 16:47:41 by rtanama           #+#    #+#             */
/*   Updated: 2024/07/11 18:19:44 by rtanama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*replace_home_with_tilde(const char *cwd, const char *home)
{
	char	*new_cwd;

	if (cwd == NULL || home == NULL)
		return (NULL);
	if (ft_strncmp(cwd, home, ft_strlen(home)) == 0)
	{
		new_cwd = malloc(ft_strlen(cwd) - ft_strlen(home) + 2);
		if (new_cwd)
		{
			new_cwd[0] = '~';
			ft_strcpy(new_cwd + 1, cwd + ft_strlen(home));
			return (new_cwd);
		}
	}
	return (ft_strdup(cwd));
}

int	init_shell(t_shell *data, char **envp)
{
	if (envp == NULL || *envp == NULL)
	{
		data->envp = (char **) malloc(sizeof(char *) * 3);
		if (!(data->envp))
			return (ERROR);
		data->envp[0] = ft_strdup("PATH=/usr/bin:/bin:/usr/sbin:/sbin");
		data->envp[1] = ft_strdup(envp_shlvl(NULL));
		data->envp[2] = NULL;
		if (!(data->envp[0] || !(data->envp[1])))
		{
			free_array_of_strings(data->envp);
			return (ERROR);
		}
	}
	else
	{
		data->envp = envp_copy(envp);
		if (!(data->envp))
			return (ERROR);
		update_shlvl(&(data->envp));
		if (!find_env_var(data->envp, "SHLVL"))
			return (ERROR);
	}
	data->username = getenv("USER");
	return (SUCCESS);
}

void	free_array_of_strings(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}
