/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:29:44 by rtammi            #+#    #+#             */
/*   Updated: 2024/10/10 13:04:29 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"

# define PS_ERROR -1
# define PS_OK 0
# define PS_SUCCESS 1

typedef struct s_push_swap
{
	t_vector	stack_a;
	t_vector	stack_b;
}				t_push_swap;

typedef struct s_sort
{
	size_t		index_a;
	size_t		index_b;
	int			cost_a;
	int			cost_b;
	int			total_cost;
	int			best_cost;
	size_t		best_index_a;
	size_t		best_index_b;
	bool		above_median_a;
	bool		above_median_b;
}				t_sort;

void	push_swap(t_vector *stack_a, t_vector *stack_b);
void	error_handler(t_vector *stack_a, t_vector *stack_b);
int		verify_args(int argc, char **argv);
int		add_elements(t_vector *stack_a, int argc, char **argv);
int 	check_duplicates(t_vector *stack);

void	reset_sort_info(t_sort *sort_info);
void	get_info_a(t_vector *stack_a, t_vector *stack_b, t_sort *sort_info);
void	get_info_b(t_vector *stack_a, t_vector *stack_b, t_sort *sort_info);
int		find_index_of_value(t_vector *stack, int value);
size_t	find_largest_index(t_vector *stack);
size_t	find_smallest_index(t_vector *stack);
void	calculate_move_cost(t_vector *stack_a, t_vector *stack_b, t_sort *sort_info);
void	move_to_b(t_vector *stack_a, t_vector *stack_b, t_sort *sort_info);
void	move_to_a(t_vector *stack_a, t_vector *stack_b, t_sort *sort_info);
void	determine_best_move_a(t_vector *stack_a, t_vector *stack_b, t_sort *sort_info);
void	determine_best_move_b(t_vector *stack_a, t_vector *stack_b, t_sort *sort_info);

void	simple_sort(t_vector *stack);
void	large_sort(t_vector *stack_a, t_vector *stack_b);

void	pa(t_vector *stack_a, t_vector *stack_b);
void	pb(t_vector *stack_a, t_vector *stack_b);
void	sa(t_vector *stack_a, bool flag);
void	sb(t_vector *stack_b, bool flag);
void	ss(t_vector *stack_a, t_vector *stack_b);
void	ra(t_vector *stack_a, bool flag);
void	rb(t_vector *stack_b, bool flag);
void	rr(t_vector *stack_a, t_vector *stack_b);
void	rra(t_vector *stack_a, bool flag);
void	rrb(t_vector *stack_b, bool flag);
void	rrr(t_vector *stack_a, t_vector *stack_b);

void	print_stack(t_vector *stack, char stack_name);

#endif
