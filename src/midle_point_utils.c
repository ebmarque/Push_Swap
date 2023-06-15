/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   midle_point_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque < ebmarque@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 12:02:22 by ebmarque          #+#    #+#             */
/*   Updated: 2023/06/11 17:16:55 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long int	last_min_call(t_stack *a, long int last_min)
{
	long int	aux_min;
	t_push		*tmp;

	tmp = a->top;
	while (tmp)
	{
		if (tmp->data > last_min)
		{
			aux_min = tmp->data;
			break ;
		}	
		tmp = tmp->next;
	}
	tmp = a->top;
	while (tmp)
	{
		if (aux_min > tmp->data && tmp->data > last_min)
			aux_min = tmp->data;
		tmp = tmp->next;
	}
	return (aux_min);
}

long int	get_last_min(t_stack *a, int call)
{
	static long int	last_min;
	long int		aux_min;
	t_push			*tmp;

	tmp = a->top;
	if (call == 0)
	{
		last_min = tmp->data;
		while (tmp)
		{
			if (last_min > tmp->data)
				last_min = tmp->data;
			tmp = tmp->next;
		}
		return (last_min);
	}
	else
	{
		aux_min = last_min_call(a, last_min);
		last_min = aux_min;
		return (last_min);
	}
}

long int	*get_org_arr(t_stack *a)
{
	long int	min_value;
	long int	*org_arr;
	int			i;
	t_push		*tmp;

	if (a->stack_size == 0)
		return (NULL);
	i = 0;
	tmp = a->top;
	org_arr = (long int *)ft_calloc(a->stack_size, sizeof(long int));
	while (i < a->stack_size)
	{
		min_value = get_last_min(a, i);
		org_arr[i] = min_value;
		tmp = tmp->next;
		i++;
	}
	return (org_arr);
}
