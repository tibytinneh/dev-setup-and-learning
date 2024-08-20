/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aang-shu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 08:47:59 by aang-shu          #+#    #+#             */
/*   Updated: 2023/09/10 08:54:37 by aang-shu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	`ft_striteri` applies function `f` to each character in the string `s`
**	passing both the character and its index as arguments to function 1f1
*/

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
