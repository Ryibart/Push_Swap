/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 19:30:11 by rtammi            #+#    #+#             */
/*   Updated: 2024/10/08 20:35:08 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	compare_ints(void *a, void *b)
{
	int int_a = *(int *)a;
	int int_b = *(int *)b;

	if (int_a < int_b)
		return -1;
	else if (int_a > int_b)
		return 1;
	else
		return 0;
}

int	find_median(t_vector *stack, size_t len)
{
	int		median;
	
	t_vector	stack_copy;
	vector_new(&stack_copy, len, stack->elem_size);
	vector_copy(&stack_copy, stack);
	vector_sort(&stack_copy, compare_ints);
	median = *(int *)vector_get(&stack_copy, len / 2);
	vector_free(&stack_copy);
	return (median);
}

void	push_chunks(t_vector *stack_a, t_vector *stack_b, int pivot)
{
	size_t	size;
	size_t	i;

	size = stack_a->len;
	i = 0;
	while (i < size)
	{
		if (*(int *)vector_get(stack_a, 0) < pivot)
			pb(stack_a, stack_b);
		else
			ra(stack_a, true);
		i++;
	}
}

void	merge_back(t_vector *stack_a, t_vector *stack_b, size_t size)
{
	while (size > 0)
	{
		pa(stack_a, stack_b);
		print_stack(stack_a, 'a');
		size--;
	}
}

void	recursive_sort(t_vector *stack_a, t_vector *stack_b, size_t size)
{
	int		pivot;
	size_t	left_size;
	size_t	right_size;
	
	if (size <= 3)
	{
		simple_sort(stack_a);
		return ;
	}
	pivot = find_median(stack_a, size);
	push_chunks(stack_a, stack_b, pivot);
	left_size = stack_a->len;
	recursive_sort(stack_a, stack_b, left_size);
	right_size = stack_b->len;
	recursive_sort(stack_b, stack_a, right_size);
	merge_back(stack_a, stack_b, right_size);
}