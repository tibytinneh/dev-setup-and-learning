/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aang-shu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 22:43:39 by aang-shu          #+#    #+#             */
/*   Updated: 2023/09/10 18:45:12 by aang-shu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	"String Length Copy"
**	Copy string to a specific size.
**
**	Safely copies a string from a source to a destination,
**	while ensuring that the desintation buffer doesn't overflow.
**	Takes care to null-terminate the destination buffer.
**	
**	The function returns the length of the source string that was copied,
**	excluding the null-terminator.	
*/

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size)
	{
		while (i < size - 1 && src[i])
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}
