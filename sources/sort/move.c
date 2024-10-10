/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:59:39 by rtammi            #+#    #+#             */
/*   Updated: 2024/10/10 14:25:26 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void move_to_a(t_vector *stack_a, t_vector *stack_b, t_sort *info)
{
    // Rotate both stacks together if beneficial
    while (info->cost_b > 0 && info->cost_a > 0) {
        if (info->above_median_a && info->above_median_b) {
            rr(stack_a, stack_b); // Rotate both
            info->cost_b--;
            info->cost_a--;
        } else if (!info->above_median_a && !info->above_median_b) {
            rrr(stack_a, stack_b); // Reverse rotate both
            info->cost_b--;
            info->cost_a--;
        }
    }

    // Rotate remaining elements in stack_b
    while (info->cost_b > 0) {
        if (info->above_median_b) {
            rb(stack_b, true);
        } else {
            rrb(stack_b, true);
        }
        info->cost_b--;
    }
    
    // Finally, push to stack_a
    pa(stack_a, stack_b);
}

void move_to_b(t_vector *stack_a, t_vector *stack_b, t_sort *info)
{
    // Rotate both stacks together if beneficial
    while (info->cost_a > 0 && info->cost_b > 0) {
        if (info->above_median_a && info->above_median_b) {
            rr(stack_a, stack_b); // Rotate both
            info->cost_a--;
            info->cost_b--;
        } else if (!info->above_median_a && !info->above_median_b) {
            rrr(stack_a, stack_b); // Reverse rotate both
            info->cost_a--;
            info->cost_b--;
        }
    }

    // Rotate remaining elements in stack_a
    while (info->cost_a > 0) {
        if (info->above_median_a) {
            ra(stack_a, true);
        } else {
            rra(stack_a, true);
        }
        info->cost_a--;
    }
    
    // Finally, push to stack_b
    pb(stack_a, stack_b);
}