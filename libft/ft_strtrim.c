/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque < ebmarque@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 14:03:04 by ebmarque          #+#    #+#             */
/*   Updated: 2023/04/23 16:03:18 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_charset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if ((unsigned char)set[i] == (unsigned char)c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimed;
	int		i;
	int		j;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (s1[i] && ft_is_charset(s1[i], set))
		i++;
	j = ft_strlen(s1) - 1;
	while (j > i && ft_is_charset(s1[j], set))
		j--;
	if (i == j && ft_is_charset(s1[i], set))
		trimed = ft_strdup("");
	else
	{
		if (ft_is_charset(s1[j], set))
			j--;
		trimed = ft_substr(s1, i, j - i + 1);
	}
	return (trimed);
}
