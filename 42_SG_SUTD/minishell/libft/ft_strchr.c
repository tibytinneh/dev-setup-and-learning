/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aang-shu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 04:29:56 by aang-shu          #+#    #+#             */
/*   Updated: 2023/09/10 18:17:01 by aang-shu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Searches for the first occurence of a character `c` in a string `str`
**
**	Returns a pointer to the first occurence of `c` within string `str`
**	Return `NULL` if `c` is not found
*/

/*	while character at str is not c
**	increment str position until null, return 0
**	exit when first occurence of c, return pointer
**
**	`c` is typecasted to (unsigned char) to ensure that the comparison between
**	`*s` (a char in str `s`) and `c` (an int representing char) is valid
*/

char	*ft_strchr(const char *str, int c)
{
	while (*str != (unsigned char) c)
		if (!*str++)
			return (0);
	return ((char *)str);
}
