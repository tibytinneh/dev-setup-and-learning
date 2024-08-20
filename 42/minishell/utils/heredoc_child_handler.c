/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_child_handler.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtanama <rtanama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 04:13:05 by rtanama           #+#    #+#             */
/*   Updated: 2024/07/14 11:09:08 by rtanama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*read_and_expand_input(t_shell *data)
{
	char	buffer[BUFSIZ];
	ssize_t	bytes_read;

	bytes_read = read(STDIN_FILENO, buffer, BUFSIZ - 1);
	if (bytes_read <= 0)
		return (NULL);
	buffer[bytes_read] = '\0';
	return (expand_env_var(buffer, data));
}

static char	*append_to_accumulated(char *accumulated, char *temp)
{
	size_t	current_len;
	size_t	temp_len;
	char	*new_accumulated;

	if (accumulated)
		current_len = ft_strlen(accumulated);
	else
		current_len = 0;
	temp_len = ft_strlen(temp);
	new_accumulated = malloc(current_len + temp_len + 1);
	if (!new_accumulated)
	{
		free(accumulated);
		free(temp);
		exit(EXIT_FAILURE);
	}
	if (accumulated)
		ft_memcpy(new_accumulated, accumulated, current_len);
	ft_memcpy(new_accumulated + current_len, temp, temp_len);
	new_accumulated[current_len + temp_len] = '\0';
	free(accumulated);
	return (new_accumulated);
}

static void	finalize_accumulated(int fd[2], char *accumulated)
{
	if (accumulated && g_exit_code != SIGINT_EXIT_CODE)
		write(fd[1], accumulated, ft_strlen(accumulated));
	free(accumulated);
}

void	handle_child_loop_heredoc(int fd[2], char *delimiter, t_shell *data)
{
	char	*temp;
	char	*accumulated;

	accumulated = NULL;
	while (TRUE && g_exit_code != SIGINT_EXIT_CODE)
	{
		ft_putstr_fd("> ", STDERR_FILENO);
		temp = read_and_expand_input(data);
		if (!temp)
			break ;
		if (ft_strncmp(temp, delimiter, ft_strlen(delimiter)) == 0
			&& temp[ft_strlen(delimiter) + 1] == '\0')
		{
			free(temp);
			break ;
		}
		accumulated = append_to_accumulated(accumulated, temp);
		free(temp);
	}
	finalize_accumulated(fd, accumulated);
}
