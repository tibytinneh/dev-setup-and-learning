/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aang-shu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:39:00 by aang-shu          #+#    #+#             */
/*   Updated: 2024/05/03 01:46:26 by aang-shu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	`ft_putendl_fd` outputs the string `s` to the given file descriptor,
**	followed by a newline
*/

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
