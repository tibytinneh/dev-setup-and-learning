/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtanama <rtanama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 01:34:28 by aang-shu          #+#    #+#             */
/*   Updated: 2024/07/14 10:56:29 by rtanama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	`ft_itoa` converts an integer `n` into a (char *) null-terminated string
**	representation of that integer.
*/

#include "libft.h"

static size_t	ft_intlen(int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	fill_itoa(char *result, int num_len, long long num)
{
	if (num == 0)
		result[0] = '0';
	if (num < 0)
	{
		result[0] = '-';
		num = -num;
	}
	result[num_len] = '\0';
	num_len--;
	while (num_len >= 0 && num > 0)
	{
		result[num_len] = num % 10 + '0';
		num /= 10;
		num_len--;
	}
}

char	*ft_itoa(int n)
{
	char		*result;
	size_t		num_len;
	long long	num;

	num = n;
	num_len = ft_intlen(n);
	result = (char *)malloc(sizeof(char) * (num_len + 1));
	if (!result)
		return (NULL);
	fill_itoa(result, num_len, num);
	return (result);
}
