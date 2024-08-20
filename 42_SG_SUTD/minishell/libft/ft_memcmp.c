/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aang-shu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:45:18 by aang-shu          #+#    #+#             */
/*   Updated: 2023/09/05 22:18:20 by aang-shu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	`ft_memcmp` compares `n` bytes of memory pointed to by `s1` & `s2`
**
**	If equal, return 0.
**	If `s1` > `s2`, return a positive value
**	If `s1` < `s2`, return a negative value
*/

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*((unsigned char *)s1 + i) == *((unsigned char *)s2 + i))
			i++;
		else
			return ((*((unsigned char *)s1 + i)) - *((unsigned char *)s2 + i));
	}
	return (0);
}
