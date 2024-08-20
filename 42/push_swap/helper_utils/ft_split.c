/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aang-shu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 00:50:19 by aang-shu          #+#    #+#             */
/*   Updated: 2024/04/14 17:37:44 by aang-shu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	count_strings(const char *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str)
			count++;
		while (*str && *str != c)
			str++;
	}
	return (count);
}

static int	ft_singlestring(char **result, char *str, char c)
{
	int	len;
	int	i;

	len = 0;
	while (str[len] && str[len] != c)
		len++;
	*result = malloc((len + 1) * sizeof(char));
	if (!*result)
		return (0);
	i = 0;
	while (i < len)
	{
		result[0][i] = str[i];
		i++;
	}
	result[0][i] = '\0';
	return (1);
}

static void	*free_strings(char **strs, int i)
{
	while (i)
		free(strs[i--]);
	free(strs);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	char	*str;
	int		i;

	if (!s)
		return (NULL);
	str = (char *) s;
	i = 0;
	result = (char **)malloc(sizeof(char *) * (count_strings(s, c) + 1));
	if (!result)
		return (NULL);
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str && !ft_singlestring(&result[i++], str, c))
			return (free_strings(result, i));
		while (*str && *str != c)
			str++;
	}
	result[i] = (NULL);
	return (result);
}

/* Testing:
cc ft_split.c ft_strlen.c libft.h 

#include <stdio.h>

int main(int ac, char **av)
{
    if (ac != 3)
// Make sure user provides exactly 2 arguments: the string and the delimiter.
    {
        printf("Usage: %s <string> <delimiter>\n", av[0]);
        return 1;
    }

    char **result = ft_split(av[1], av[2][0]);
// We take the first character of the second argument as the delimiter.

    for (int i = 0; result && result[i]; i++)
    {
        printf("Segment %d: %s\n", i, result[i]);
        free(result[i]);  // Free each segment after use.
    }
    free(result);  // Free the overall result array.

    return 0;
}
*/
