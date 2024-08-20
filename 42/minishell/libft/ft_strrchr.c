/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aang-shu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 04:48:58 by aang-shu          #+#    #+#             */
/*   Updated: 2023/09/10 18:26:54 by aang-shu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Finds the last occurence of a character in a string
**	and returns a pointer to that location
**
**	Returns a pointer to the last occurence of char `c` within string `str`
**	Returns `NULL` if `c` is not found
*/

/*	find strlen + '\0', assign to i
**	while loop from backwards index str, if str[i] != c
**	ends when i less than 0, return null
**	else return pointer to last occurence of c
*/

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	unsigned int	i;

	i = ft_strlen(str);
	while (str[i] != (unsigned char) c)
		if (!i--)
			return (0);
	return ((char *)str + i);
}
