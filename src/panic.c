/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque < ebmarque@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 12:27:25 by ebmarque          #+#    #+#             */
/*   Updated: 2023/06/11 22:14:19 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	get_max_min(int argc, char *argv[], long int *max, long int *min)
{
	int			i;
	long int	nbr;

	*max = ft_atoi(argv[1]);
	*min = ft_atoi(argv[1]);
	i = 1;
	nbr = ft_atoi(argv[i]);
	while (i < argc)
	{
		nbr = ft_atoi(argv[i]);
		if (nbr > *max)
			*max = nbr;
		if (nbr < *min)
			*min = nbr;
		i++;
	}
}

void	free_stack(t_push *head)
{
	t_push	*tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

void	panic(t_stack *a, t_stack *b)
{
	if (a->top)
		free_stack(a->top);
	if (b->top)
		free_stack(b->top);
}
