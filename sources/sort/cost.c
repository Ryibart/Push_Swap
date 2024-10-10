/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:34:48 by rtammi            #+#    #+#             */
/*   Updated: 2024/10/10 12:49:50 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	a_cost(t_vector *stack_a, t_sort *sort_info, size_t mid_a)
{
	if (sort_info->index_a <= mid_a)
		sort_info->cost_a = sort_info->index_a;
	else
		sort_info->cost_a = stack_a->len - sort_info->index_a;
}

static void	b_cost(t_vector *stack_b, t_sort *sort_info, size_t mid_b)
{
	if (sort_info->index_b <= mid_b)
		sort_info->cost_b = sort_info->index_b;
	else
		sort_info->cost_b = stack_b->len - sort_info->index_b;
}

static void	total_cost(t_sort *sort_info, size_t mid_a, size_t mid_b)
{
	if ((sort_info->index_a <= mid_a && sort_info->index_b <= mid_b) ||
		(sort_info->index_a > mid_a && sort_info->index_b > mid_b))
	{
		if (sort_info->cost_a > sort_info->cost_b)
			sort_info->total_cost = sort_info->cost_a;
		else
			sort_info->total_cost = sort_info->cost_b;
	}
	else
		sort_info->total_cost = sort_info->cost_a - sort_info->cost_b;
}

void calculate_move_cost(t_vector *stack_a, t_vector *stack_b, t_sort *sort_info)
{
	size_t	mid_a;
	size_t	mid_b;

	mid_a = stack_a->len / 2;
	mid_b = stack_b->len / 2;
	a_cost(stack_a, sort_info, mid_a);
	b_cost(stack_b, sort_info, mid_b);
	total_cost(sort_info, mid_a, mid_b);
}
