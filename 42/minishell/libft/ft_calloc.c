/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aang-shu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 19:44:28 by aang-shu          #+#    #+#             */
/*   Updated: 2023/09/06 12:51:02 by aang-shu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** `ft_calloc` allocates memory for an array of elements
**	and initializes the memory to zero
**	
**	`nbr` number of elements
**	`size` size of each element
**	Returns a pointer to the allocated memory
**	(NULL) if allocation failed
*/

#include "libft.h"

void	*ft_calloc(size_t nbr, size_t size)
{
	size_t	total_size;
	void	*ptr;

	total_size = nbr * size;
	ptr = NULL;
	ptr = malloc(total_size);
	if (ptr != NULL)
		ft_bzero(ptr, total_size);
	return (ptr);
}
