/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtanama <rtanama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 23:01:30 by rtanama           #+#    #+#             */
/*   Updated: 2024/05/22 23:12:16 by rtanama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	to_number(const unsigned char c)
{
	return (c - '0');
}

long	ft_atol(char *str)
{
	long	out;
	int		sign;

	out = 0;
	sign = 1;
	while (ft_isspace(*str))
		str ++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str ++;
	}
	while (ft_isdigit(*str))
	{
		out = out * 10 + to_number(*str);
		str ++;
	}
	return (out * sign);
}
