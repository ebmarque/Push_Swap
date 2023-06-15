/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque < ebmarque@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:20:52 by ebmarque          #+#    #+#             */
/*   Updated: 2023/06/15 10:36:39 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_push
{
	long int		data;
	struct s_push	*target_node;
	bool			above_median;
	bool			cheapest;
	int				push_price;
	int				current_position;
	struct s_push	*next;
}				t_push;

typedef struct s_stack
{
	t_push	*top;
	int		stack_size;
	char	c;
}			t_stack;

void		game_init(int argc, char *argv[],
				t_stack *stack_a, t_stack *stack_b);
void		init_stack(t_stack *stack_a, t_stack *stack_b);
int			arg_arr(int argc, char *argv[]);

//CHECK PARAMETERES
int			check_args(int argc, char *argv[]);
int			invalid_char(int argc, char *argv[]);
int			invalid_number(int argc, char *argv[]);
int			check_repetition(int argc, char *argv[]);
void		get_max_min(int argc, char *argv[], long int *max, long int *min);
int			check_hash(int argc, char *argv[], bool *p_hash, bool *n_hash);

//LIST UTILS
t_push		*new_node(int content);
t_push		*last_node(t_push *head);
void		add_back(t_push **head, t_push *new);
void		add_front(t_push **head, t_push *new);
void		get_stack(int argc, char *argv[], t_stack *stack_a);
void		init_node(t_push *node);

//MOVES
void		swap_one(t_stack *head, bool silent);
void		swap_two(t_stack *a, t_stack *b, bool silent);
void		push_to(t_stack *b, t_stack *a, bool silent);
void		rotate_one(t_push **head, char c, bool silent);
void		rotate_two(t_push **head_a, t_push **head_b, bool silent);
void		r_rotate(t_push **head, char c, int mode, bool silent);
void		r_rotate_two(t_push **head_a, t_push **head_b, bool silent);

//ALGORITIMO ESTUPIDO;
void		dumb(t_stack *a, t_stack *b);
void		get_index(int *b_index, int *s_index, t_push *tmp);
void		dumb_rotate(t_stack *a, t_stack *b);
void		tree_numbers(t_stack *a);
int			find_min(t_push *head);
int			get_case_2(int b_index, int s_index);
int			get_case(t_stack *a);

//ERROR CASES
void		panic(t_stack *a, t_stack *b);
void		free_stack(t_push *head);

//AUX
long int	*get_array(t_stack *head);
void		choose_algo(t_stack *a, t_stack *b);
int			is_organized(t_push *a);

// MIDLE POINT
void		midle_point_a(t_stack *a, t_stack *b);
long int	*get_org_arr(t_stack *a);
long int	get_last_min(t_stack *a, int call);
long int	last_min_call(t_stack *a, long int last_min);
int			first_ocur_a(t_stack *a, long int m_point);
int			last_ocur_a(t_stack *a, long int m_point);
void		decide_rotate_a(t_stack *a, long int m_point);

//HARD_CODE
t_push		*get_target_node(t_stack *a, t_push *reference);
void		init_stack_a(t_stack *a);
void		init_stack_b(t_stack *a, t_stack *b);
void		hard_code(t_stack *a, t_stack *b);
int			calc_price(t_push *target_node, t_push *reference, t_stack *b);
void		rotate_together_up(t_stack *a, t_stack *b, int move_a, int move_b);
void		rotate_together_down(t_stack *a, t_stack *b,
				int move_a, int move_b);
void		get_to_the_top(t_stack *n, t_push *node, int move);
void		do_the_math(t_stack *a, t_stack *b);
#endif