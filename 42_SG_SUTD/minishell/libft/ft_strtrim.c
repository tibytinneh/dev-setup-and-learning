/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtanama <rtanama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 00:53:21 by aang-shu          #+#    #+#             */
/*   Updated: 2024/07/14 10:56:46 by rtanama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	`ft_strtrim` returns a trimmed copy of `s1`
**	with the characters specified in `set` removed
**	from the beginning and the end of the string
**		`s1`: the string that needs to be trimmed
**		`set`: a string containing the set of characters to be trimmed
*/

/*
**	`ft_strchr` helper function used to check for character occurence
**	Searches for the first occurence of `c` in str `str`
**  Returns a pointer to the first occurence of `c` within string `str`
**  Return `NULL` if `c` is not found
**	char	*ft_strchr(const char *str, int c)
**
**	`ft_strlcpy` helper function (String Length Copy)
**	size_t	ft_strlcpy(char *dest, const char *src, size_t size);
*/

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new;
	size_t	start;
	size_t	end;
	size_t	len;

	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	len = end - start;
	new = (char *)malloc(len + 1);
	if (!new)
		return (NULL);
	ft_strlcpy(new, s1 + start, len + 1);
	return (new);
}
