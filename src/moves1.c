/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque < ebmarque@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 13:02:58 by ebmarque          #+#    #+#             */
/*   Updated: 2023/06/15 09:53:28 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_one(t_stack *head, bool silent)
{
	int	tmp;

	if (head->stack_size > 1)
	{
		tmp = head->top->data;
		head->top->data = head->top->next->data;
		head->top->next->data = tmp;
		if (!silent)
		{
			ft_putchar_fd('s', 1);
			ft_putchar_fd(head->c, 1);
			ft_putchar_fd('\n', 1);
		}
	}
}

void	swap_two(t_stack *a, t_stack *b, bool silent)
{
	int	tmp;

	if (a->stack_size > 1 && b->stack_size > 1)
	{
		tmp = a->top->data;
		a->top->data = a->top->next->data;
		a->top->next->data = tmp;
		tmp = b->top->data;
		b->top->data = b->top->next->data;
		b->top->next->data = tmp;
		if (!silent)
			ft_putstr_fd("ss\n", 1);
	}
}

void	push_to(t_stack *b, t_stack *a, bool silent)
{
	t_push	*tmp;

	tmp = b->top;
	if (b->stack_size > 0)
	{
		b->top = b->top->next;
		b->stack_size--;
		add_front(&a->top, tmp);
		a->stack_size++;
		if (!silent)
		{
			ft_putchar_fd('p', 1);
			ft_putchar_fd(a->c, 1);
			ft_putchar_fd('\n', 1);
		}
	}
}

void	rotate_one(t_push **head, char c, bool silent)
{
	t_push	*current;

	current = *head;
	if (*head == NULL || (*head)->next == NULL)
		return ;
	while (current->next != NULL)
		current = current->next;
	current->next = *head;
	*head = (*head)->next;
	current->next->next = NULL;
	if (!silent)
	{
		ft_putchar_fd('r', 1);
		ft_putchar_fd(c, 1);
		ft_putchar_fd('\n', 1);
	}
}

void	rotate_two(t_push **head_a, t_push **head_b, bool silent)
{
	t_push	*current_a;
	t_push	*current_b;

	current_a = *head_a;
	current_b = *head_b;
	if (*head_a == NULL || (*head_a)->next == NULL)
		return ;
	while (current_a->next != NULL)
		current_a = current_a->next;
	current_a->next = *head_a;
	*head_a = (*head_a)->next;
	current_a->next->next = NULL;
	if (*head_b == NULL || (*head_b)->next == NULL)
		return ;
	while (current_b->next != NULL)
		current_b = current_b->next;
	current_b->next = *head_b;
	*head_b = (*head_b)->next;
	current_b->next->next = NULL;
	if (!silent)
		ft_putstr_fd("rr\n", 1);
}
