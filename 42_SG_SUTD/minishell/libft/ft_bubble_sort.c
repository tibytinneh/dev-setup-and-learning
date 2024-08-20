/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtanama <rtanama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 10:44:01 by rtanama           #+#    #+#             */
/*   Updated: 2024/07/14 10:52:39 by rtanama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bubble_sort(char **char_arr, int size)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (ft_strcmp(char_arr[j], char_arr[j + 1]) > 0)
			{
				temp = char_arr[j];
				char_arr[j] = char_arr[j + 1];
				char_arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}
