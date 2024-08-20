/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtanama <rtanama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 02:34:30 by aang-shu          #+#    #+#             */
/*   Updated: 2024/07/14 10:56:21 by rtanama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	execute_clear_cmd(void)
{
	clear();
	return (SUCCESS);
}

void	clear(void)
{
	ft_putstr_fd("\033[H\033[J", STDOUT_FILENO);
}
