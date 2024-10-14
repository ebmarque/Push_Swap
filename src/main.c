/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:24:34 by ebmarque          #+#    #+#             */
/*   Updated: 2024/10/14 13:36:46 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	already_sorted(int argc, char *argv[])
{
	int			i;
	long int	curr;
	long int	next;

	i = 1;
	while (i < argc - 1)
	{
		curr = ft_atoi(argv[i]);
		next = ft_atoi(argv[i + 1]);
		if (curr > next)
			return (0);
		i++;
	}
	return (1);
}

void	game_init(int argc, char *argv[], t_stack *stack_a, t_stack *stack_b)
{
	if (check_args(argc, argv) < 0)
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	if (argc == 2 || already_sorted(argc, argv))
		exit(EXIT_SUCCESS);
	init_stack(stack_a, stack_b);
	get_stack(argc, argv, stack_a);
}

int	main(int argc, char *argv[])
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc >= 2)
	{
		game_init(argc, argv, &stack_a, &stack_b);
		choose_algo(&stack_a, &stack_b);
		panic(&stack_a, &stack_b);
	}
	return (0);
}
