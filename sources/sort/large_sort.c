/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 19:30:11 by rtammi            #+#    #+#             */
/*   Updated: 2024/10/10 13:03:02 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_elements_to_b(t_vector *stack_a, t_vector *stack_b)
{
	t_sort	sort_info;
	
	reset_sort_info(&sort_info);
	while (stack_a->len > 3)
	{
		reset_sort_info(&sort_info);
		determine_best_move_b(stack_a, stack_b, &sort_info);
		calculate_move_cost(stack_a, stack_b, &sort_info);
		move_to_b(stack_a, stack_b, &sort_info);
	}
}

void	sort_remaining(t_vector *stack_a)
{
	if (stack_a->len <= 3)
		simple_sort(stack_a);
}

void	merge_back_to_a(t_vector *stack_a, t_vector *stack_b)
{
	t_sort sort_info;

	reset_sort_info(&sort_info);
	while (stack_b->len > 0)
	{
		reset_sort_info(&sort_info);
		determine_best_move_a(stack_a, stack_b, &sort_info);
		calculate_move_cost(stack_a, stack_b, &sort_info);
		move_to_a(stack_a, stack_b, &sort_info);
	}
}

void	large_sort(t_vector *stack_a, t_vector *stack_b)
{
	push_elements_to_b(stack_a, stack_b);
	sort_remaining(stack_a);
	merge_back_to_a(stack_a, stack_b);
}