/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtanama <rtanama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 02:29:18 by aang-shu          #+#    #+#             */
/*   Updated: 2024/07/14 17:38:44 by rtanama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

volatile sig_atomic_t	g_exit_code = EXIT_SUCCESS;

char	*get_prompt(void)
{
	char	cwd[PATH_MAX];
	char	*prompt;
	char	*username;
	char	*current_directory;
	char	*cwd_replaced;

	getcwd(cwd, PATH_MAX);
	cwd_replaced = replace_home_with_tilde(cwd, getenv("HOME"));
	if (!cwd_replaced)
		return (ft_strdup("HammuShell 🐹: "));
	username = ft_strjoin(getenv("USER"), "@");
	current_directory = ft_strjoin(username, cwd_replaced);
	prompt = ft_strjoin("\001\033[44m\002", current_directory);
	prompt = ft_strjoin_free(prompt, " 🐹\001\033[0m\002");
	prompt = ft_strjoin_free(prompt, " ");
	free(username);
	free(current_directory);
	free(cwd_replaced);
	return (prompt);
}

int	take_input(t_shell *data)
{
	char	*prompt;

	prompt = get_prompt();
	data->input_buf = readline(prompt);
	free(prompt);
	if (!data->input_buf)
		return (EOF);
	if (*data->input_buf)
	{
		add_history(data->input_buf);
		data->input_str = ft_strdup(data->input_buf);
		free(data->input_buf);
		return (SUCCESS);
	}
	free(data->input_buf);
	return (ERROR);
}

static void	init(int ac, char **av, char **envp, t_shell *data)
{
	int	status;

	(void) av;
	if (ac != 1)
	{
		print_error("shell", E2BIG, "too many arguments");
		exit(EXIT_FAILURE);
	}
	status = init_shell(data, envp);
	if (status != SUCCESS)
	{
		print_error("init", 0, "failed to initialize shell");
		exit(EXIT_FAILURE);
	}
	init_signal_hook();
}

int	main(int ac, char **av, char **envp)
{
	t_shell	data;
	int		status;

	init(ac, av, envp, &data);
	status = EXIT_SUCCESS;
	while (TRUE)
	{
		if (status == EXIT)
			break ;
		data.input_check = take_input(&data);
		if (data.input_check == EOF)
			break ;
		else if (data.input_check == ERROR)
			continue ;
		status = process_input(&data);
		free(data.input_str);
	}
	free_array_of_strings(data.envp);
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
	exit (g_exit_code);
}
