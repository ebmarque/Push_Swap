/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 21:11:08 by ebmarque          #+#    #+#             */
/*   Updated: 2023/04/23 20:58:18 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*pdst;
	const unsigned char	*psrc;

	pdst = dest;
	psrc = src;
	if (pdst == psrc)
		return (pdst);
	if (pdst > psrc)
	{
		pdst += n - 1;
		psrc += n - 1;
		while (n--)
			*pdst-- = *psrc--;
	}
	else
	{
		while (n--)
			*pdst++ = *psrc++;
	}
	return (dest);
}
