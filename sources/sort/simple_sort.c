/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtammi <rtammi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 19:28:42 by rtammi            #+#    #+#             */
/*   Updated: 2024/10/08 19:56:38 by rtammi           ###   ########.fr       */
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
	if (a < b && b < c) // can be taken out to save lines
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

void	simple_sort(t_vector *stack)
{
	if (stack->len < 2)
		return ;
	if (stack->len == 2)
		sort_two(stack);
	else if (stack->len == 3)
		sort_three(stack);
}