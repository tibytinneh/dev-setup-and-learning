/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aang-shu <smallhammu@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 03:49:47 by aang-shu          #+#    #+#             */
/*   Updated: 2024/05/13 03:59:13 by aang-shu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* joins s1 to s2, frees s1.
	returns s1+s2;
*/

#include "libft.h"

char	*ft_strjoin_free(char *s1, char const *s2)
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
	if (s1)
		free(s1);
	return (new);
}
