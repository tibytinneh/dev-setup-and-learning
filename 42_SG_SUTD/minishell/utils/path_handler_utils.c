/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_handler_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtanama <rtanama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 07:22:00 by rtanama           #+#    #+#             */
/*   Updated: 2024/07/14 11:12:25 by rtanama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*extract_pathvar(char **envp)
{
	size_t	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (ft_strtrim(envp[i], "PATH="));
		i++;
	}
	return (NULL);
}

char	*append_path(char *path, char *cmd)
{
	char	*full_path;
	char	*abs_path;

	full_path = ft_strjoin(path, "/");
	abs_path = ft_strjoin(full_path, cmd);
	free(full_path);
	return (abs_path);
}

void	handle_child_sigquit(int signum)
{
	(void) signum;
	g_exit_code = SIGQUIT_EXIT_CODE;
	ft_putstr_fd("Quit (core dumped)\n", STDERR_FILENO);
}
