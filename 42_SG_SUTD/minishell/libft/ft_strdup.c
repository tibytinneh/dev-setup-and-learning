/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aang-shu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:55:01 by aang-shu          #+#    #+#             */
/*   Updated: 2024/04/30 17:35:52 by aang-shu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	`ft_strdup` (string duplicate)
**	duplicates a given null-terminated string `s1`
**	Returns a pointer to a new string containing a duplicate of `s1`
**	Returns `NULL` if allocation fails or `s1` is `NULL
**
**	allocate memory with `ft_strnew` -> `s1` NULL/ malloc check
**	-> copies characters from `s1` to `res` -> return `res`
**
**	`ft_strnew` (new string) helper function
**	allocates memory for a new string of the specified size
**	and initializes it with null characters
**
**	malloc for `size + 1` -> malloc check -> b_zero allocated memory
*/

#include "libft.h"

static char	*ft_strnew(size_t size)
{
	char	*res;

	res = (char *)malloc(size + 1);
	if (!res)
		return (NULL);
	ft_bzero(res, sizeof(char) * (size + 1));
	return (res);
}

char	*ft_strdup(const char *s1)
{
	char	*res;
	int		i;

	res = ft_strnew(ft_strlen(s1));
	if (!s1 || !res)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	return (res);
}
