/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque < ebmarque@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 12:11:12 by ebmarque          #+#    #+#             */
/*   Updated: 2023/06/04 16:30:25 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(char *str, char *sep)
{
	char	**split;
	int		i;
	int		j;

	j = 0;
	i = 0;
	split = (char **)malloc(sizeof(char *) * (ft_count_words(str, sep) + 1));
	if (split == NULL)
		return (NULL);
	while (str[i] && j < ft_count_words(str, sep))
	{
		while (str[i] && ft_strchr(sep, str[i]) != NULL)
			i++;
		split[j] = ft_strndup(&str[i], ft_word_length(&str[i], sep));
		if (split[j] == NULL)
		{
			ft_free_split((void **)split, j);
			return (NULL);
		}
		i += ft_word_length(&str[i], sep);
		j++;
	}
	split[j] = NULL;
	return (split);
}
