/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aang-shu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 05:02:18 by aang-shu          #+#    #+#             */
/*   Updated: 2023/09/10 06:36:58 by aang-shu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	`ft_strmapi` applies a custom function `f` to each character in the str `s`
**	Returns a new string, modified with the function.
**
**	`char const *s`:
**		a pointer to a string to apply the function on
**	char (*f)(unsigned int, char):
**		a function pointer named `f` that can point to a function:
**			- return_type: (char)
**			- parameters: (unsigned int, char)
**
**	result = strdup(s) -> fail check
**	-> execute function `f` on every element in `result` -> return result
*/

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*result;

	i = 0;
	result = ft_strdup(s);
	if (result == NULL)
		return (NULL);
	while (result[i])
	{
		result[i] = f(i, result[i]);
		i++;
	}
	return (result);
}
