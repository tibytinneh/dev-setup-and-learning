/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aang-shu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:33:11 by aang-shu          #+#    #+#             */
/*   Updated: 2024/04/18 03:35:35 by aang-shu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	`ft_putstr_fd` outputs the string `str` to the given file descriptor
*/

#include "../push_swap.h"

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}
