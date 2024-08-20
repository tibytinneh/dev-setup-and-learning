/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtanama <rtanama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 03:04:57 by rtanama           #+#    #+#             */
/*   Updated: 2024/07/11 19:40:01 by rtanama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_error(char *command, int error_number, char *message)
{
	char	*error_message;

	error_message = ft_strjoin("HammuShell 🐹: ", command);
	ft_putstr_fd(error_message, 2);
	ft_putstr_fd(": ", 2);
	if (error_number)
		ft_putendl_fd(strerror(error_number), 2);
	else
		ft_putendl_fd(message, 2);
	free(error_message);
}
