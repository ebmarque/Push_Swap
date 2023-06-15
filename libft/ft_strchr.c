/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque < ebmarque@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 22:50:09 by ebmarque          #+#    #+#             */
/*   Updated: 2023/06/04 12:24:08 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	str = (char *)s;
	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if ((unsigned char)str[i] == (unsigned char)c)
			return (&str[i]);
		i++;
	}
	if ((unsigned char )str[i] == (unsigned char)c)
		return (&str[i]);
	return (NULL);
}
