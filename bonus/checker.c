/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque < ebmarque@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 20:34:37 by ebmarque          #+#    #+#             */
/*   Updated: 2023/06/15 12:23:38 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_command(char *line)
{
	if (!ft_strncmp(line, "pa", 3) || !ft_strncmp(line, "pb", 3)
		|| !ft_strncmp(line, "ra", 3) || !ft_strncmp(line, "rb", 3)
		|| !ft_strncmp(line, "rra", 4) || !ft_strncmp(line, "rrb", 4)
		|| !ft_strncmp(line, "rrr", 4) || !ft_strncmp(line, "sa", 3)
		|| !ft_strncmp(line, "sb", 3) || !ft_strncmp(line, "ss", 3)
		|| !ft_strncmp(line, "rr", 3))
		return (0);
	return (-1);
}

void	do_command(t_stack *a, t_stack *b, char *cmd)
{
	if (!ft_strncmp(cmd, "pa", 3))
		push_to(a, b, true);
	else if (!ft_strncmp(cmd, "pb", 3))
		push_to(b, a, true);
	else if (!ft_strncmp(cmd, "ra", 3))
		rotate_one(&a->top, a->c, true);
	else if (!ft_strncmp(cmd, "rb", 3))
		rotate_one(&b->top, b->c, true);
	else if (!ft_strncmp(cmd, "rb", 3))
		rotate_two(&a->top, &b->top, true);
	else if (!ft_strncmp(cmd, "rra", 4))
		r_rotate(&a->top, a->c, 1, true);
	else if (!ft_strncmp(cmd, "rrb", 4))
		r_rotate(&b->top, b->c, 1, true);
	else if (!ft_strncmp(cmd, "rrr", 4))
		r_rotate_two(&a->top, &b->top, true);
	else if (!ft_strncmp(cmd, "sa", 3))
		swap_one(a, true);
	else if (!ft_strncmp(cmd, "sb", 3))
		swap_one(b, true);
	else if (!ft_strncmp(cmd, "ss", 3))
		swap_two(a, b, true);
}

void	get_line(t_stack *a, t_stack *b, int i)
{
	char	*line;
	char	c;

	line = malloc(4);
	while (read(0, &c, 1))
	{
		if (c == '\n' || i == 3)
		{
			line[i] = '\0';
			if (check_command(line) < 0)
			{
				free(line);
				ft_putstr_fd("Error\n", 2);
				panic(a, b);
				exit(1);
			}
			do_command(a, b, line);
			i = 0;
			free(line);
			line = malloc(4);
		}
		else
			line[i++] = c;
	}
	free(line);
}

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;

	if (check_args(argc, argv) < 0)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	if (argc < 2)
		return (0);
	init_stack(&a, &b);
	get_stack(argc, argv, &a);
	get_line(&a, &b, 0);
	if (is_organized(a.top))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	panic(&a, &b);
	return (0);
}
