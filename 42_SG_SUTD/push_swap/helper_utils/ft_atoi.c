/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aang-shu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 19:10:30 by aang-shu          #+#    #+#             */
/*   Updated: 2024/04/24 08:57:45 by aang-shu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

static int	ft_iswhitespace(int c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

long	ft_atoi(const char *str)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while (ft_iswhitespace(*((unsigned char *)str + i)))
		i++;
	if (*((unsigned char *)str + i) == '-'
		|| *((unsigned char *)str + i) == '+')
	{
		if (*((unsigned char *)str + i) == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(*((unsigned char *)str + i)))
	{
		result = result * 10 + (*((unsigned char *)str + i) - '0');
		i++;
	}
	return (result * sign);
}
