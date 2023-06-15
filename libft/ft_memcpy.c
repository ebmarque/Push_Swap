/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 21:01:47 by ebmarque          #+#    #+#             */
/*   Updated: 2023/04/23 19:37:28 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*p;
	const unsigned char	*s;
	size_t				i;

	if (!dest && !src)
		return (NULL);
	p = dest;
	s = src;
	i = 0;
	while (i < n)
	{
		*p = *s;
		p++;
		s++;
		i++;
	}
	return (dest);
}
