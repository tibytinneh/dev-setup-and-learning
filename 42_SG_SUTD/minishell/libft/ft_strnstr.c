/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aang-shu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 05:34:04 by aang-shu          #+#    #+#             */
/*   Updated: 2023/08/17 21:07:23 by aang-shu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	finds the first occurrence of the substr `needle` in the str `haystack`
**		up to a specified length
**
**		`str` the string to be searched
**		`tofind` the substring to be found
**		`len` the maximum number of characters to search within `str`
**	
**	Returns a pointer to the first character of the matching substring
**			if `needle` is found within the str `haystack`
**			with a maxiumum search length of `len`
**	Returns `NULL`
**			if `needle` is not found within the str `haystack`
**			with a maximum search length of `len`
**			or the search length is exhausted
*/

/*
**	size_t		needlelen	// Length of the substring to find (`tofind`)
**	size_t		remaining	// Remaining search length within `str`
**	const char	*haystack	// Pointer to current pos in `str`
**	const char	*needle		// POinter to current pos in `tofind`
**	
**	Calculate the total length of `tofind`, assign the value to `needlelen`
**	
**	If: `tofind` is an empty string,
**		return a pointer to the start of `str`
**	While:	`str` still has characters (not reached null-terminator '\0')
**			The remaining search length is sufficient for a potential match
**		If: The current char in `str` matches the first char in `tofind`
**		Set the remaining search length
**		Initialize `haystack` pointer to current position in `str`
**		Initialize `needle` pointer to current position in `tofind`
**
**		While: there's still search space/ search length
**				*haystack == *needle
**			Move to the next character in `haystack`
**			Move to the next character in `needle`
**			Decrement the remaining search length
**
**		If: the current character at needle is the null-terminator '\0'
**			indicating a successful match,
**			Return a pointer to the first char of the matching substr `str`
**
**		`str` is incremented to move to the next character in `str`
**		`len` is decremented to update the remaining search length
**
**	Return `NULL` if no match is found within the specified search length
*/

/*
char	*ft_strnstr(char *str, char *tofind, size_t len)
{
	size_t		needlelen;
	size_t		remaining;
	const char	*haystack;
	const char	*needle;

	needlelen = ft_strlen(tofind);
	if (*tofind == '\0')
		return ((char *)str);
	while (*str && len >= needlelen)
	{
		if (*str == *tofind)
		{
			remaining = len;
			haystack = str;
			needle = tofind;
			while (*needle && *haystack == *needle
				&& remaining > 0)
			{
				haystack++;
				needle++;
				remaining--;
			}
			if (*needle == '\0')
				return ((char *)str);
		}
		str++;
		len--;
	}
	return (NULL);
}
*/

/*	declare i for index counter.
**  Calculate the total length of `tofind`, assign the value to `needlelen`
**  
**  If: `tofind` is an empty string,
**      return a pointer to the start of `str`
**  While:  `str` still has characters (not reached null-terminator '\0')
**          The remaining search length is sufficient for a potential match
**		Initialize i as 0.
**      while: tofind[i] != '\0'
**		&& the current char in `str` matches the first char in `tofind`
**				Increment i until	tofind[i] == '\0'
**							or		str[i] doesn't match tofind[i]
**				If tofind[i] == '\0'
**     			The current character at needle is the null-terminator '\0'
**				indicating a successful match,
**				Return a pointer to the first char of the matching substr `str`
**
**      `str` is incremented to move to the next character in `str`
**      `len` is decremented to update the remaining search length
**
**  Return `NULL` if no match is found within the specified search length
*/

char	*ft_strnstr(const char *str, const char *tofind, size_t len)
{
	size_t	i;
	size_t	needlelen;

	needlelen = ft_strlen(tofind);
	if (*tofind == '\0')
		return ((char *)str);
	while (*str && len-- >= needlelen)
	{
		i = 0;
		while (tofind[i] && str[i] == tofind[i])
			i++;
		if (!tofind[i])
			return ((char *) str);
		str++;
	}
	return (NULL);
}
