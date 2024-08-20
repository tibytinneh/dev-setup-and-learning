/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_builtins.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtanama <rtanama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 19:29:45 by aang-shu          #+#    #+#             */
/*   Updated: 2024/07/14 10:39:47 by rtanama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_BUILTINS_H
# define MINISHELL_BUILTINS_H

# include "minishell.h"

/* -------------------------------------------------------------------------- */
/*                                  COMMANDS                                  */
/* -------------------------------------------------------------------------- */
int		execute_builtin_cmd(char *command, char **args, t_shell *data);
int		execute_echo_cmd(char **args);
int		execute_cd_cmd(char **args);
int		execute_pwd_cmd(void);
/* --------------------------------- EXPORT --------------------------------- */
int		execute_export_cmd(char **args, t_shell *data);
void	print_env_error(char *arg, char *message);
char	*get_key(char *arg);
char	*remove_quotes(const char *arg);
int		export_without_argument(char ***envp);
/* -------------------------------------------------------------------------- */
int		execute_unset_cmd(char **args, t_shell *data);
int		execute_env_cmd(char **envp);
int		execute_exit_cmd(char **args);
int		execute_clear_cmd(void);
void	clear(void);

#endif
