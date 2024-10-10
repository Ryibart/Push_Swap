/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:12:02 by rtammi            #+#    #+#             */
/*   Updated: 2024/10/10 13:17:20 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void reset_sort_info(t_sort *sort_info)
{
	sort_info->best_cost = INT_MAX;
	sort_info->best_index_a = 0;
	sort_info->best_index_b = 0;
	sort_info->cost_a = 0;
	sort_info->cost_b = 0;
	sort_info->total_cost = 0;
	sort_info->index_a = 0;
	sort_info->index_b = 0;
}

size_t find_largest_index(t_vector *stack)
{
	int largest;
	size_t largest_idx;
	size_t i;

	largest = INT_MIN;
	largest_idx = 0;
	i = 0;
	while (i < stack->len)
	{
		int value = *(int *)vector_get(stack, i);
		if (value > largest)
		{
			largest = value;
			largest_idx = i;
		}
		i++;
	}
	return (largest_idx);
}

size_t find_smallest_index(t_vector *stack)
{
	int smallest;
	size_t smallest_idx;
	size_t i;

	smallest = INT_MAX;
	smallest_idx = 0;
	i = 0;
	while (i < stack->len)
	{
		int value = *(int *)vector_get(stack, i);
		if (value < smallest)
		{
			smallest = value;
			smallest_idx = i;
		}
		i++;
	}
	return (smallest_idx);
}

int find_index_of_value(t_vector *stack, int value) {
    size_t idx = 0;

    while (idx < stack->len) {
        if (*(int *)vector_get(stack, idx) == value)
            return idx;  // Return index if found
        idx++;
    }
    return stack->len; // Not found, return length
}