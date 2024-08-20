/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_init_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtanama <rtanama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 02:25:27 by aang-shu          #+#    #+#             */
/*   Updated: 2024/07/14 10:21:26 by rtanama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sigint_handler(int signum)
{
	(void)signum;
	g_exit_code = 130;
	ft_putstr_fd("\n", STDOUT_FILENO);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	child_sigint_handler(int signum)
{
	(void) signum;
	g_exit_code = 130;
}

void	child_sigint_handler_external(int signum)
{
	(void) signum;
	g_exit_code = 130;
	ft_putstr_fd("\n", STDOUT_FILENO);
}

void	sigquit_handler(int signum)
{
	(void)signum;
}

void	init_signal_hook(void)
{
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, sigquit_handler);
	disable_ctrl_backslash_echo();
}
