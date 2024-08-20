/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_defines.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtanama <rtanama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 19:20:58 by aang-shu          #+#    #+#             */
/*   Updated: 2024/07/14 07:34:03 by rtanama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_DEFINES_H
# define MINISHELL_DEFINES_H

/* -------------------------------------------------------------------------- */
/*                                   STATUS                                   */
/* -------------------------------------------------------------------------- */
# define TRUE 1
# define FALSE 0
# define SUCCESS 0
# define EXIT 3
# define ERROR 1
# define INTERRUPTED 4
# define NOT_FOUND 2
# define NO_PERMISSION 126
# define SIGINT_EXIT_CODE 130
# define SIGQUIT_EXIT_CODE 131
# define COMMAND_NOT_FOUND_EXIT_CODE 127
# define PERMISSION_DENIED_EXIT_CODE 126

/* -------------------------------------------------------------------------- */
/*                                  BUILT-INS                                 */
/* -------------------------------------------------------------------------- */
# define ECHO_CMD "echo"
# define CD_CMD "cd"
# define PWD_CMD "pwd"
# define EXPORT_CMD "export"
# define UNSET_CMD "unset"
# define ENV_CMD "env"
# define EXIT_CMD "exit"
# define CLEAR_CMD "clear"

#endif
