/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_code.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque < ebmarque@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:45:43 by ebmarque          #+#    #+#             */
/*   Updated: 2023/06/15 10:04:13 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_push	*get_target_node(t_stack *a, t_push *reference)
{
	t_push	*temp;
	t_push	*smallest_biggest;

	temp = a->top;
	smallest_biggest = a->top;
	while (temp)
	{
		if (temp->data > reference->data)
			smallest_biggest = temp;
		temp = temp->next;
	}
	temp = a->top;
	while (temp)
	{
		if (smallest_biggest->data > temp->data && temp->data > reference->data)
			smallest_biggest = temp;
		temp = temp->next;
	}
	return (smallest_biggest);
}

void	set_cheapest(t_push *b)
{
	t_push	*temp;
	int		min_price;

	temp = b;
	min_price = temp->push_price;
	while (temp)
	{
		if (temp->push_price < min_price)
			min_price = temp->push_price;
		temp = temp->next;
	}
	temp = b;
	while (temp)
	{
		if (temp->push_price == min_price)
			temp->cheapest = true;
		else
			temp->cheapest = false;
		temp = temp->next;
	}
}

void	init_stack_b(t_stack *a, t_stack *b)
{
	t_push	*temp;
	int		i;

	i = -1;
	temp = b->top;
	while (temp && ++i >= 0)
	{
		if (i <= b->stack_size / 2)
			temp->above_median = true;
		else
			temp->above_median = false;
		temp->current_position = i;
		temp->target_node = get_target_node(a, temp);
		temp->push_price = calc_price(temp->target_node, temp, b);
		temp = temp->next;
	}
	set_cheapest(b->top);
}

void	get_to_the_top(t_stack *n, t_push *node, int move)
{
	if (node->above_median)
	{
		while (move > 0)
		{
			rotate_one(&n->top, n->c, false);
			move--;
		}
	}
	else
	{
		while (move > 0)
		{
			r_rotate(&n->top, n->c, 1, false);
			move--;
		}
	}
}

void	hard_code(t_stack *a, t_stack *b)
{
	int	organize_back;

	organize_back = 0;
	midle_point_a(a, b);
	while (b->stack_size > 0)
	{
		init_stack_a(a);
		init_stack_b(a, b);
		do_the_math(a, b);
	}
	organize_back = find_min(a->top);
	if (organize_back <= a->stack_size / 2)
	{
		while (organize_back-- > 0)
			rotate_one(&a->top, a->c, false);
	}
	else
	{
		organize_back = a->stack_size - organize_back;
		while (organize_back-- > 0)
			r_rotate(&a->top, a->c, 1, false);
	}	
}
