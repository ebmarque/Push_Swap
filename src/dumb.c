/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dumb.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque < ebmarque@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 21:11:57 by ebmarque          #+#    #+#             */
/*   Updated: 2023/06/15 10:12:43 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_min(t_push *head)
{
	int		index;
	int		min;
	int		count;
	t_push	*tmp;

	index = 0;
	count = 0;
	tmp = head;
	min = tmp->data;
	while (tmp)
	{
		if (min > tmp->data)
		{
			min = tmp->data;
			index = count;
		}
		count++;
		tmp = tmp->next;
	}
	return (index);
}

void	dumb_rotate(t_stack *a, t_stack *b)
{
	int	rotates;

	while (a->stack_size > 3)
	{
		rotates = find_min(a->top);
		if (rotates <= a->stack_size / 2)
		{
			while (rotates > 0)
			{
				rotate_one(&a->top, a->c, false);
				rotates--;
			}
		}
		else
		{
			while (rotates < a->stack_size)
			{
				r_rotate(&a->top, a->c, 1, false);
				rotates++;
			}
		}
		push_to(a, b, false);
	}
}

void	dumb(t_stack *a, t_stack *b)
{
	dumb_rotate(a, b);
	tree_numbers(a);
	while (b->stack_size > 0)
		push_to(b, a, false);
}
