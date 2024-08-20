/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_of_bits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aang-shu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:21:58 by aang-shu          #+#    #+#             */
/*   Updated: 2024/04/24 10:22:13 by aang-shu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	number_of_bits(int count)
{
	int	bits;

	bits = 0;
	while ((1 << bits) < count)
		bits++;
	return (bits);
}