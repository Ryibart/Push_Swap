/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:45:13 by rtammi            #+#    #+#             */
/*   Updated: 2024/10/08 16:48:11 by rtammi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_vector *stack)
{
	if (*(int *)vector_get(stack, 0) > *(int *)vector_get(stack, 1))
	{
		sa(stack, true);
		print_stack(stack, 'a');
		return ;
	}
}

void	sort_three(t_vector *stack)
{
	int	a;
	int	b;
	int	c;

	a = *(int *)vector_get(stack, 0);
	b = *(int *)vector_get(stack, 1);
	c = *(int *)vector_get(stack, 2);
	if (a < b && b < c)
		return ;
	if (a > b && b > c)
	{
		sa(stack, true);
		rra(stack, true);
	}
	else if ((a > c && c > b) || (c < a && a > b))
	{
		ra(stack, true);
	}
	else if (b > a && a > c)
		rra(stack, true);
	else if (b > c && c > a)
	{
		sa(stack, true);
		ra(stack, true);
	}
	else if (a > b && b < c)
		sa(stack, true);
}

void	simple_sort(t_vector *stack_a)
{
	if (stack_a->len < 2)
		return ;
	if (stack_a->len == 2)
		sort_two(stack_a);
	else if (stack_a->len == 3)
		sort_three(stack_a);
}

void	push_swap(t_vector *stack_a, t_vector *stack_b)
{
	(void)stack_b;
	if (stack_a->len <= 3)
		simple_sort(stack_a);
	else
	{
		// big_sort(stack_a, stack_b);
	}
	return ;
}
