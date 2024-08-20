/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aang-shu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 19:10:30 by aang-shu          #+#    #+#             */
/*   Updated: 2023/09/06 18:54:22 by aang-shu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	`ft_atoi` converts amd returns a string representation of an integer
**	to an actual integer value
*/

/*
**	`ft_iswhitespace` checks for any whitespace character
**	Space(32) ' '
**	Horizontal tab(9) '\t'
**	New line(10) '\n'
**	Vertical tab(11) '\v'
**	Form feed(12)   '\f'
**	Carriage return(13) '\r'
*/

#include "libft.h"

static int	ft_iswhitespace(int c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;
	int	i;

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
