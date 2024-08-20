/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aang-shu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 22:46:09 by aang-shu          #+#    #+#             */
/*   Updated: 2024/04/18 00:17:31 by aang-shu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	*ft_bzero(void *str, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*((unsigned char *) str + i) = 0;
		i++;
	}
	return (str);
}

static char	*ft_strnew(size_t size)
{
	char	*res;

	res = (char *)malloc(size + 1);
	if (!res)
		return (NULL);
	ft_bzero(res, sizeof(char) * (size + 1));
	return (res);
}

char	*ft_strdup(char *s1)
{
	char	*res;
	int		i;

	if (!s1)
		return (NULL);
	res = ft_strnew(ft_strlen(s1));
	if (!res)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	return (res);
}
