/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aang-shu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 20:52:26 by aang-shu          #+#    #+#             */
/*   Updated: 2023/09/05 22:01:23 by aang-shu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	`ft_isascii` checks if character fits into the ASCII character set
**	Within '\0'(0) to 'DEL'(127)
*/
int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
