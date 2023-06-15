/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 20:31:44 by ebmarque          #+#    #+#             */
/*   Updated: 2023/04/17 18:33:54 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	value;
	size_t			i;

	p = s;
	value = c;
	i = 0;
	while (i < n)
	{
		*p = value;
		p++;
		i++;
	}
	return (s);
}
