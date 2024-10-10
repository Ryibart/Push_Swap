/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:49:45 by rtammi            #+#    #+#             */
/*   Updated: 2024/10/10 14:20:29 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// FIXTHIS: NULL checks & error handling

// Predicate function to check if a value is less than the target
bool is_less_than_target(void *value, int target_value)
{
    return (*(int *)value < target_value);
}

// Predicate function to check if a value is greater than the target
bool is_greater_than_target(void *value, int target_value)
{
    return (*(int *)value > target_value);
}

// Function to find the target in stack B
static void target_in_b(t_vector *stack_b, int value, t_sort *sort_info)
{
    size_t idx = 0;
    int nearest = INT_MIN;

    // Use the predicate function to find the nearest value less than the target
    while (idx < stack_b->len)
    {
        if (is_less_than_target(vector_get(stack_b, idx), value))
        {
            nearest = *(int *)vector_get(stack_b, idx);
        }
        idx++;
    }

    if (nearest == INT_MIN)
        sort_info->index_b = find_largest_index(stack_b);
    else
        sort_info->index_b = find_index_of_value(stack_b, nearest);
}

// Function to find the target in stack A
static void target_in_a(t_vector *stack_a, int value, t_sort *sort_info)
{
    size_t idx = 0;
    int nearest = INT_MAX;

    // Use the predicate function to find the nearest value greater than the target
    while (idx < stack_a->len)
    {
        if (is_greater_than_target(vector_get(stack_a, idx), value))
        {
            nearest = *(int *)vector_get(stack_a, idx);
        }
        idx++;
    }

    if (nearest == INT_MAX)
        sort_info->index_a = find_smallest_index(stack_a);
    else
        sort_info->index_a = find_index_of_value(stack_a, nearest);
}

// Function to determine the best move for stack A based on stack B
void determine_best_move_a(t_vector *stack_a, t_vector *stack_b, t_sort *sort_info)
{
    size_t idx = 0;

    while (idx < stack_b->len)
    {
        int target_value = *(int *)vector_get(stack_b, idx);
        target_in_a(stack_a, target_value, sort_info);
        calculate_move_cost(stack_a, stack_b, sort_info);

        if (sort_info->total_cost < sort_info->best_cost)
        {
            sort_info->best_index_a = sort_info->index_a;
            sort_info->best_index_b = sort_info->index_b;
            sort_info->best_cost = sort_info->total_cost;
        }
        idx++;
    }
}

// Function to determine the best move for stack B based on stack A
void determine_best_move_b(t_vector *stack_a, t_vector *stack_b, t_sort *sort_info)
{
    size_t idx = 0;

    while (idx < stack_a->len)
    {
        int target_value = *(int *)vector_get(stack_a, idx);
        target_in_b(stack_b, target_value, sort_info);
        calculate_move_cost(stack_a, stack_b, sort_info);

        if (sort_info->total_cost < sort_info->best_cost)
        {
            sort_info->best_index_a = sort_info->index_a;
            sort_info->best_index_b = sort_info->index_b;
            sort_info->best_cost = sort_info->total_cost;
        }
        idx++;
    }
}