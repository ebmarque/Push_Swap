/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque < ebmarque@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:42:26 by ebmarque          #+#    #+#             */
/*   Updated: 2023/06/19 14:20:44 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_case_2(int b_index, int s_index)
{
	if (b_index == 0 && s_index == 1)
		return (1);
	if (b_index == 0 && s_index == 2)
		return (2);
	if (b_index == 1 && s_index == 2)
		return (3);
	if (b_index == 2 && s_index == 1)
		return (4);
	if (b_index == 1 && s_index == 0)
		return (5);
	return (0);
}

void	get_index(int *b_index, int *s_index, t_push *tmp)
{
	int	i;
	int	big;
	int	small;

	i = 0;
	big = tmp->data;
	small = tmp->data;
	while (i < 3)
	{
		if (big <= tmp->data)
		{
			big = tmp->data;
			*b_index = i;
		}
		if (small >= tmp->data)
		{
			small = tmp->data;
			*s_index = i;
		}
		tmp = tmp->next;
		i++;
	}
}

int	get_case(t_stack *a)
{
	int		b_index;
	int		s_index;
	t_push	*tmp;

	tmp = a->top;
	b_index = 0;
	s_index = 0;
	get_index(&b_index, &s_index, tmp);
	return (get_case_2(b_index, s_index));
}

void	three_numbers(t_stack *a)
{
	int	case_r;

	case_r = get_case(a);
	if (case_r == 1)
		rotate_one(&a->top, a->c, false);
	else if (case_r == 2)
	{
		swap_one(a, false);
		r_rotate(&a->top, a->c, 1, false);
	}
	else if (case_r == 3)
		r_rotate(&a->top, a->c, 1, false);
	else if (case_r == 4)
		swap_one(a, false);
	else if (case_r == 5)
	{
		swap_one(a, false);
		rotate_one(&a->top, a->c, false);
	}
}

void	choose_algo(t_stack *a, t_stack *b)
{
	if (a->stack_size == 2)
		swap_one(a, false);
	else if (a->stack_size < 6)
		dumb(a, b);
	else
		hard_code(a, b);
}
