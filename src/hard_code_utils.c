/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_code_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque < ebmarque@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:39:42 by ebmarque          #+#    #+#             */
/*   Updated: 2023/06/15 10:03:47 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_node(t_push *node)
{
	node->above_median = false;
	node->cheapest = false;
	node->current_position = 0;
	node->push_price = 0;
	node->target_node = NULL;
}

void	init_stack_a(t_stack *a)
{
	t_push	*temp;
	int		i;

	i = -1;
	temp = a->top;
	while (temp && ++i >= 0)
	{
		if (i <= a->stack_size / 2)
			temp->above_median = true;
		else
		{
			temp->above_median = false;
		}
		temp->current_position = i;
		temp->cheapest = false;
		if (temp->above_median)
			temp->push_price = temp->current_position;
		else
			temp->push_price = a->stack_size - temp->current_position;
		temp->target_node = NULL;
		temp = temp->next;
	}
}

int	calc_price(t_push *target_node, t_push *reference, t_stack *b)
{
	int	b_push_price;

	if (reference->above_median)
		b_push_price = reference->current_position;
	else
		b_push_price = b->stack_size - reference->current_position;
	if (target_node->above_median == reference->above_median)
	{
		if (b_push_price >= target_node->push_price)
			return (b_push_price);
		return (target_node->push_price);
	}
	return (b_push_price + target_node->push_price);
}

void	rotate_together_up(t_stack *a, t_stack *b, int move_a, int move_b)
{
	while (move_a > 0 && move_b > 0)
	{
		rotate_two(&a->top, &b->top, false);
		move_b--;
		move_a--;
	}
	if (move_a > 0)
	{
		while (move_a > 0)
		{
			rotate_one(&a->top, a->c, false);
			move_a--;
		}
	}
	else
	{
		while (move_b > 0)
		{
			rotate_one(&b->top, b->c, false);
			move_b--;
		}
	}
}

void	rotate_together_down(t_stack *a, t_stack *b, int move_a, int move_b)
{
	while (move_a > 0 && move_b > 0)
	{
		r_rotate_two(&a->top, &b->top, false);
		move_b--;
		move_a--;
	}
	if (move_a > 0)
	{
		while (move_a > 0)
		{
			r_rotate(&a->top, a->c, 1, false);
			move_a--;
		}
	}
	else
	{
		while (move_b > 0)
		{
			r_rotate(&b->top, b->c, 1, false);
			move_b--;
		}
	}
}
