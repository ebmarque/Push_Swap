/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque < ebmarque@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:22:26 by ebmarque          #+#    #+#             */
/*   Updated: 2023/04/20 13:27:39 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	number;

	number = n;
	if (number < 0)
	{
		write(fd, "-", 1);
		number = -number;
	}
	if (number >= 10)
		ft_putnbr_fd(number / 10, fd);
	number = number % 10;
	ft_putchar_fd(number + '0', fd);
}
