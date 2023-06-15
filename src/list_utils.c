/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque < ebmarque@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:44:53 by ebmarque          #+#    #+#             */
/*   Updated: 2023/06/14 14:07:07 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_push	*new_node(int content)
{
	t_push	*new;

	new = malloc(sizeof(t_push));
	if (new == NULL)
		return (NULL);
	new->next = NULL;
	new->data = content;
	return (new);
}

t_push	*last_node(t_push *head)
{
	t_push	*tmp;

	tmp = head;
	if (!tmp)
		return (NULL);
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	add_back(t_push **head, t_push *new)
{
	t_push	*tmp;

	if (!*head || !new)
		return ;
	if (!*head)
	{
		*head = new;
		return ;
	}
	tmp = last_node(*head);
	tmp->next = new;
}

void	get_stack(int argc, char *argv[], t_stack *stack_a)
{
	int		i;
	t_push	*tmp;

	i = 1;
	stack_a->top = new_node(ft_atoi(argv[i++]));
	stack_a->stack_size++;
	init_node(stack_a->top);
	while (i < argc)
	{
		tmp = new_node(ft_atoi(argv[i]));
		add_back(&stack_a->top, tmp);
		stack_a->stack_size++;
		i++;
	}
}

void	add_front(t_push **head, t_push *new)
{
	if (new == NULL)
		return ;
	new->next = *head;
	*head = new;
}
