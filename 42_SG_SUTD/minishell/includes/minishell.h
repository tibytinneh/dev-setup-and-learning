/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtanama <rtanama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 01:40:06 by aang-shu          #+#    #+#             */
/*   Updated: 2024/07/14 09:38:16 by rtanama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/* -------------------------------------------------------------------------- */
/*                           LIBRARIES AND INCLUDES                           */
/* -------------------------------------------------------------------------- */
# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <sys/wait.h>
# include <limits.h>
# include <linux/limits.h>
# include <fcntl.h>
# include <errno.h>
# include <termios.h>

/* -------------------------------------------------------------------------- */
/*                                 SUB-HEADERS                                */
/* -------------------------------------------------------------------------- */
# include "minishell_defines.h"
# include "minishell_struct.h"
# include "minishell_functions.h"
# include "minishell_builtins.h"

/* -------------------------------------------------------------------------- */
/*                                  VARIABLES                                 */
/* -------------------------------------------------------------------------- */
extern volatile sig_atomic_t	g_exit_code;

#endif
