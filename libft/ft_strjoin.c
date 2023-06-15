/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 13:50:26 by ebmarque          #+#    #+#             */
/*   Updated: 2023/04/17 18:29:23 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		total_size;
	char	*join;

	i = ft_strlen(s1);
	j = 0;
	total_size = (ft_strlen(s1) + ft_strlen(s2));
	join = (char *)malloc(sizeof(s1[0]) * total_size + 1);
	if (join == NULL)
		return (NULL);
	while (s1[j])
	{
		join[j] = s1[j];
		j++;
	}
	j = 0;
	while (s2[j])
	{
		join[i + j] = s2[j];
		j++;
	}
	join[i + j] = '\0';
	return (join);
}
