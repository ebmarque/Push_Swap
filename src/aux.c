/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque < ebmarque@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:29:19 by ebmarque          #+#    #+#             */
/*   Updated: 2023/06/15 12:27:52 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long int	*get_array(t_stack *head)
{
	long int	*result;
	int			i;
	t_push		*tmp;

	result = (long int *)malloc(sizeof(long int) * head->stack_size);
	i = 0;
	tmp = head->top;
	while (tmp)
	{
		result[i] = tmp->data;
		tmp = tmp->next;
		i++;
	}
	return (result);
}

int	is_organized(t_push *head)
{
	t_push	*tmp;

	tmp = head;
	while (tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	do_the_math(t_stack *a, t_stack *b)
{
	t_push	*temp;
	int		move_a;
	int		move_b;

	temp = b->top;
	while (temp->cheapest == false)
		temp = temp->next;
	move_a = temp->target_node->push_price;
	if (temp->above_median)
		move_b = temp->current_position;
	else
		move_b = b->stack_size - temp->current_position;
	if (temp->above_median == true
		&& temp->target_node->above_median == true)
		rotate_together_up(a, b, move_a, move_b);
	else if (temp->above_median == false
		&& temp->target_node->above_median == false)
		rotate_together_down(a, b, move_a, move_b);
	else
	{
		get_to_the_top(a, temp->target_node, move_a);
		get_to_the_top(b, temp, move_b);
	}
	push_to(b, a, false);
}

void	init_stack(t_stack *stack_a, t_stack *stack_b)
{
	stack_a->top = NULL;
	stack_a->c = 'a';
	stack_a->stack_size = 0;
	stack_b->top = NULL;
	stack_b->c = 'b';
	stack_b->stack_size = 0;
}
