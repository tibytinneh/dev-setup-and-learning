/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aang-shu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 19:40:00 by aang-shu          #+#    #+#             */
/*   Updated: 2023/09/05 21:58:50 by aang-shu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** `ft_bzero` sets a block of memory to zero
*/

#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	ft_memset(str, 0, n);
}