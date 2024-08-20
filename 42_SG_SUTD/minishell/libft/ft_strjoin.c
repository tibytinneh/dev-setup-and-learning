/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtanama <rtanama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 19:30:59 by aang-shu          #+#    #+#             */
/*   Updated: 2024/07/14 10:56:42 by rtanama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	`ft_strjoin` allocates and returns a new string which is
**	the concatenation of `s1` and `s2`
**	Returns `NULL` if the allocation fails
*/

/*	helper functions
**	`ft_strlcpy` (String Length Copy) copies until size - 1 or !src
**	`ft_strlcat` (String Length Concatenate)
**
**	size_t	ft_strlcpy(char *dest, const char *src, size_t size)
**	Concatenate string to a specific size, overwriting null-terminator bytes,
**	size_t	ft_strlcat(char *dest, const char *src, size_t size)
**
*/

#include "libft.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*new;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	ft_strlcpy(new, s1, len + 1);
	ft_strlcat(new, s2, len + 1);
	return (new);
}
