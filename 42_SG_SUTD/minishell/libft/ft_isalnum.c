/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aang-shu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 20:49:21 by aang-shu          #+#    #+#             */
/*   Updated: 2023/09/06 12:51:11 by aang-shu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	`ft_isalnum` checks for alphabetic or number character
**	Alphabets within 'A'(65) to 'Z'(90) or 'a'(97) to 'z'(122)
**				OR
**	Digits within '0'(48) to '9'(57)
*/

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
