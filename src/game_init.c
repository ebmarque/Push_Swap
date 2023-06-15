/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque < ebmarque@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:27:41 by ebmarque          #+#    #+#             */
/*   Updated: 2023/06/14 19:56:10 by ebmarque         ###   ########.fr       */
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

int	check_hash(int argc, char *argv[], bool *p_hash, bool *n_hash)
{
	long int	num;

	num = ft_atoi(argv[argc - 1]);
	while (--argc > 0)
	{
		num = ft_atoi(argv[argc]);
		if (num < 0)
		{
			num = -num;
			if (n_hash[num] == true)
				return (-1);
			n_hash[num] = true;
		}
		else
		{
			if (p_hash[num] == true)
				return (-1);
			p_hash[num] = true;
		}
	}
	return (0);
}

int	check_repetition(int argc, char *argv[])
{
	bool			*positive_hash;
	bool			*negative_hash;
	long int		max;
	long int		min;

	max = ft_atoi(argv[1]);
	min = ft_atoi(argv[1]);
	get_max_min(argc, argv, &max, &min);
	if (min < 0)
		min = -min;
	positive_hash = ft_calloc(max + 1, sizeof(bool));
	negative_hash = ft_calloc(min + 1, sizeof(bool));
	if (check_hash(argc, argv, positive_hash, negative_hash) < 0)
	{
		free(positive_hash);
		free(negative_hash);
		return (-1);
	}
	free(positive_hash);
	free(negative_hash);
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
