/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtanama <rtanama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 22:56:43 by aang-shu          #+#    #+#             */
/*   Updated: 2024/07/10 17:29:02 by rtanama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dest[j] && j < size)
		j++;
	while (src[i] && j + i + 1 < size)
	{
		dest[j + i] = src[i];
		i++;
	}
	if (j + i < size)
		dest[j + i] = '\0';
	return (j + ft_strlen(src));
}
