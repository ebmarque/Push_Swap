/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:27:41 by ebmarque          #+#    #+#             */
/*   Updated: 2023/06/18 17:12:08 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	invalid_char(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] == '-' || argv[i][j] == '+') && j != 0)
				return (-1);
			if (argv[i][j] == '-' || argv[i][j] == '+')
				if (!(argv[i][j + 1] >= '0' && argv[i][j + 1] <= '9'))
					return (-1);
			if (argv[i][j] != '-' && argv[i][j] != '+')
				if (argv[i][j] < '0' || argv[i][j] > '9')
					return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	invalid_number(int argc, char *argv[])
{
	int			i;
	long int	number;

	i = 1;
	while (i < argc)
	{
		number = ft_atoi(argv[i]);
		if (number < INT_MIN || number > INT_MAX)
			return (-1);
		i++;
	}
	return (0);
}

int	check_repetition(int argc, char *argv[])
{
	long int *arr;
	int	i;
	int	j;

	arr = malloc(sizeof(long int) * argc - 1);
	i = -1;
	while (++i < argc)
		arr[i] = ft_atoi(argv[i]);
	i = -1;
	while (++i < argc - 1)
	{
		j = i;
		while (++j < argc)
		{
			if (arr[i] == arr[j])
			{
				free(arr);
				return (-1);
			}
		}
	}
	free(arr);
	return (0);
}

int	check_args(int argc, char *argv[])
{
	if (argc > 2)
	{
		if (invalid_char(argc, argv) < 0 || invalid_number(argc, argv) < 0
			|| check_repetition(argc, argv) < 0)
			return (-1);
	}
	else
	{
		if (invalid_char(argc, argv) < 0 || invalid_number(argc, argv) < 0)
			return (-1);
	}
	return (0);
}
