/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aang-shu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:40:54 by aang-shu          #+#    #+#             */
/*   Updated: 2024/05/03 01:46:33 by aang-shu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	`ft_putnbr_fd` outputs the integer `n` to the given file descriptor
*/

#include "libft.h"

static void	recur_fd(int n, int fd)
{
	if (n >= 10 || n <= -10)
		recur_fd(n / 10, fd);
	n %= 10;
	if (n < 0)
		n = -n;
	write(fd, &"0123456789"[n], 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		ft_putchar_fd('-', fd);
	recur_fd(n, fd);
}
