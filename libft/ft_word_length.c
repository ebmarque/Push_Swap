/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_length.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque < ebmarque@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 12:48:33 by ebmarque          #+#    #+#             */
/*   Updated: 2023/06/04 16:22:34 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_word_length(char *str, char *sep)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	while (str[i] != '\0' && ft_strchr(sep, str[i]) == NULL)
	{
		len++;
		i++;
	}
	return (len);
}
