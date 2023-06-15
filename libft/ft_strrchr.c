/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque < ebmarque@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:52:29 by ebmarque          #+#    #+#             */
/*   Updated: 2023/04/23 12:09:38 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*pointer;
	int			i;

	i = 0;
	pointer = s;
	while (s[i])
	{
		if (s[i + 1] == '\0' && c == '\0')
			return ((char *)(pointer + 1));
		i++;
		pointer++;
	}
	while (i >= 0)
	{
		if ((unsigned char)s[i] == (unsigned char)c)
		{
			pointer = &(s[i]);
			return ((char *)pointer);
		}
		i--;
	}
	return (0);
}
