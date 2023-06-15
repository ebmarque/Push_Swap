/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque < ebmarque@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 12:15:54 by ebmarque          #+#    #+#             */
/*   Updated: 2023/06/04 12:38:32 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_words(char *str, char *sep)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		while (ft_strchr(sep, str[i]) != NULL && str[i])
			i++;
		if (ft_strchr(sep, str[i]) == NULL && str[i])
		{
			words++;
			while (ft_strchr(sep, str[i]) == NULL && str[i])
				i++;
		}
	}
	return (words);
}
