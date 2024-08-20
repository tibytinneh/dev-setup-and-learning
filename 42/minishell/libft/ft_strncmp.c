/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aa <aa@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:13:41 by aang-shu          #+#    #+#             */
/*   Updated: 2024/04/04 02:26:37 by aa               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	`strncmp` compares the two strings s1 and s2, using unsigned characters,
**
**	Compares only the first (at most) `n` bytes of `s1` and `s2`
**		Return `0` if `s1` and `s2` are equal
**		Return a negative value if s1 is less than s2
**		Return a positive value if s1 is greater than s2
*/

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && i < n && s1[i] && s2[i])
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
