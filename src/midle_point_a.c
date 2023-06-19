/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   midle_point_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque < ebmarque@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:41:01 by ebmarque          #+#    #+#             */
/*   Updated: 2023/06/19 14:16:33 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	first_ocur_a(t_stack *a, long int m_point)
{
	int		next_point_ra;
	t_push	*tmp;

	next_point_ra = 0;
	tmp = a->top;
	while (tmp)
	{
		if (tmp->data < m_point)
			break ;
		next_point_ra++;
		tmp = tmp->next;
	}
	return (next_point_ra);
}

int	last_ocur_a(t_stack *a, long int m_point)
{
	int		index;
	int		next_point_rra;
	t_push	*tmp;

	index = 0;
	next_point_rra = 0;
	tmp = a->top;
	while (tmp)
	{
		if (tmp->data < m_point)
			next_point_rra = a->stack_size - index;
		index++;
		tmp = tmp->next;
	}
	return (next_point_rra);
}

void	decide_rotate_a(t_stack *a, long int m_point)
{
	int		next_point_ra;
	int		next_point_rra;

	next_point_ra = first_ocur_a(a, m_point);
	next_point_rra = last_ocur_a(a, m_point);
	if (next_point_ra < next_point_rra)
	{
		while (next_point_ra > 0)
		{
			rotate_one(&a->top, a->c, false);
			next_point_ra--;
		}
	}
	else
	{
		while (next_point_rra > 0)
		{
			r_rotate(&a->top, a->c, 1, false);
			next_point_rra--;
		}
	}
}

void	midle_point_a(t_stack *a, t_stack *b)
{
	long int	*org_arr;
	int			nb_elements;
	long int	m_point;

	while (a->stack_size > 2)
	{
		org_arr = get_org_arr(a);
		m_point = org_arr[a->stack_size / 2];
		nb_elements = (a->stack_size / 2);
		while (nb_elements > 0)
		{
			if (a->top->data < m_point)
			{
				push_to(a, b, false);
				nb_elements--;
			}
			else
				decide_rotate_a(a, m_point);
		}	
		free(org_arr);
	}
}
