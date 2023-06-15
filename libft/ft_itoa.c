/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque < ebmarque@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 12:27:47 by ebmarque          #+#    #+#             */
/*   Updated: 2023/04/20 18:01:24 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_count_digits(int n)
{
	int	digits;

	digits = 1;
	if (n < 0)
	{
		digits++;
		n = -n;
	}
	while (n / 10 > 0)
	{
		digits++;
		n /= 10;
	}
	return (digits);
}

static void	ft_fill_result(int n, char *result, int digits)
{
	int	check;

	check = 0;
	result[digits] = '\0';
	while (digits > check)
	{
		if (n < 0)
		{
			result[0] = '-';
			n = -n;
			check++;
		}
		else
		{
			result[digits - 1] = n % 10 + '0';
			n = n / 10;
			digits--;
		}
	}
}

char	*ft_itoa(int n)
{
	char	*result;
	int		digits;

	digits = ft_count_digits(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	result = (char *)malloc(sizeof(char) * (digits + 1));
	if (result == NULL)
		return (NULL);
	ft_fill_result(n, result, digits);
	return (result);
}
