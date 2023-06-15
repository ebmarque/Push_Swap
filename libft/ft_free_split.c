/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque < ebmarque@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 12:40:19 by ebmarque          #+#    #+#             */
/*   Updated: 2023/06/04 12:42:56 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_split(void **array, int position)
{
	int	i;

	i = 0;
	while (i < position)
	{
		free(array[i]);
		i++;
	}
	free(array[i]);
	free(array);
}
