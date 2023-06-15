/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque < ebmarque@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 13:02:58 by ebmarque          #+#    #+#             */
/*   Updated: 2023/06/15 10:06:33 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	r_rotate(t_push **head, char c, int mode, bool silent)
{
	t_push	*current;
	t_push	*prev;

	current = *head;
	prev = NULL;
	if (*head == NULL || (*head)->next == NULL)
		return ;
	while (current->next != NULL)
	{
		prev = current;
		current = current->next;
	}
	prev->next = NULL;
	current->next = *head;
	*head = current;
	if (!silent)
	{
		if (mode == 1)
		{
			ft_putstr_fd("rr", 1);
			ft_putchar_fd(c, 1);
			ft_putchar_fd('\n', 1);
		}
	}
}

void	r_rotate_two(t_push **head_a, t_push **head_b, bool silent)
{
	r_rotate(head_a, 'a', 0, silent);
	r_rotate(head_b, 'b', 0, silent);
	if (!silent)
		ft_putstr_fd("rrr\n", 1);
}
